#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
const int MAXN = 1000 + 10;
int x[MAXN], y[MAXN];

double solve(int i, int j, int k) {
    double a = y[j] - y[i];
    double b = x[i] - x[j];
    double ret = a*(x[k]-x[i]) + b*(y[k] - y[i]);
    ret = fabs(ret) / sqrt(a*a + b*b);
    return ret/2;
}



int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);
    double ret = INT_MAX;
    for (int i = 0; i < n; i++) {
        ret = min(solve((i+1)%n, (i-1+n)%n, i), ret);
    }
    printf("%.10f\n", ret);
    return 0;
}