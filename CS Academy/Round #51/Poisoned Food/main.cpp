#include <iostream>
#include <math.h>
using namespace std;
double eps = 1e-6;

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int type = -1;
    double rate = 2;
    int a, b;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a, &b);
        double tmp = (double) b / a;
        if (tmp < rate && fabs(rate-tmp) > eps) {
            rate = tmp;
            type = i;
        }
    }
    cout << type << endl;
    return 0;
}