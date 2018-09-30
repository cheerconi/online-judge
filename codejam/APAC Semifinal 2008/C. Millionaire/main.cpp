#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
double unit[16];
const int total = 1000000;
const double eps = 1e-6;
double dp[16][1<<16];

int get(int i, double cur) {
    if (cur > total) cur = total;
    double ratio = cur / unit[i];
    int tmp = ratio;
    if (fabs((double)(tmp+1) - ratio) < eps) return tmp+1;
    return tmp;
}
int main() {
    freopen("test.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    double cur = total;
    for (int i = 0; i <= 15; i++) {
        unit[i] = cur;
        cur /= 2;
    }
    dp[0][1] = 1;
    int T, m, x;
    double p;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> m >> p >> x;
        for (int i = 1; i <= m; i++) {
            cur = unit[i];
            int j = 1;
            while (fabs(cur-total) > eps) {
                dp[i][j] = 0;
                for (double tmp = unit[i]; fabs(tmp-cur) < eps || cur-tmp > 0; tmp += unit[i]) {
                    dp[i][j] = max(dp[i][j], p*dp[i-1][get(i-1, cur+tmp)] + (1-p)*dp[i-1][get(i-1, cur-tmp)]);
                }
                cur += unit[i];
                j++;
            }
            dp[i][j] = 1;
        }
        printf("Case #%d: %.6f\n", t, dp[m][get(m, x)]);
    }
    return 0;
}