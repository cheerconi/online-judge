#include <iostream>
#include <math.h>
const double eps = 1e-9;
double exp(double p, double q) {
    double ret = 0;
    int cnt = 1;
    double factor = 1;
    while (p < 1 && fabs(p-1) > eps) {
        ret += cnt++ * p * factor;
        factor *= 1 - p;
        p += q;
    }
    ret += cnt * factor;
    return ret;
}
double power(int i) {
    double ret = 1;
    while (i--) {
        ret *= 2;
    }
    return ret;
}
int main() {
//    freopen("test.txt", "r", stdin);
    int p, q, n;
    scanf("%d%d%d", &p, &q, &n);
    double dq = q / 100.0;
    double ret = 0;
    for (int i = 0; i < n; i++) {
        int tmp_p = (int)(p / power(i));
        double dp = tmp_p / 100.0;
        double delta = exp(dp, dq);
        ret += delta;
        if (tmp_p == 0) {
            ret += (n-i-1)*delta;
            break;
        }
    }
    printf("%.2f\n", ret);


}