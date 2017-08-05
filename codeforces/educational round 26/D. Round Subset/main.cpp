#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef long long LL;
const int MAXN = 210;
int dp[15000][MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    memset(dp, 0x80, sizeof(dp));
    int n, k, cnt = 0;
    scanf("%d%d", &n, &k);
    LL a;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &a);
        int num2 = 0, num5 = 0;
        while (a % 2 == 0) {
            a >>= 1;
            num2++;
        }
        cnt += num2;
        while (a % 5 == 0) {
            a /= 5;
            num5++;
        }
        for (int j = min(i, k); j > 0; j--) {
            for (int t = cnt; t >= num2; t--) {
                dp[t][j] = max(dp[t][j], dp[t-num2][j-1]+num5);
            }
        }
    }
    int ret = 0;
    for (int i = 0; i <= cnt; i++) {
        ret = max(ret, min(dp[i][k], i));
    }
    cout << ret << endl;


}