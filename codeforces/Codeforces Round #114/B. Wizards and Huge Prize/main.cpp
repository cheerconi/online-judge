#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long double LD;
typedef pair<int, int> pii;
const int MAXN = 200 + 10;
LD dp[2][MAXN][MAXN];
pii items[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    int n, l, k;
    cin >> n >> l >> k;
    for (int i = 0; i < n; i++) {
        cin >> items[i].second;
    }
    for (int i = 0; i < n; i++) {
        cin >> items[i].first;
    }
    sort(items, items+n, greater<pii>());
    int cur = 0;
    dp[cur][0][k] = 1;
    for (int i = 0; i < n; i++) {
        for (int a = 0; a < MAXN; a++) {
            for (int b = 0; b < MAXN; b++) {
                dp[1-cur][a][b] = 0;
            }
        }
        for (int a = 0; a <= i; a++) {
            for (int b = 0; b < MAXN; b++) {
                if (items[i].first == -1) {
                    if (b-1 >= 0) {
                        dp[1-cur][a+1][b-1] += dp[cur][a][b] * items[i].second / 100;
                    }
                }
                else {
                    dp[1-cur][a+1][min(MAXN-1, items[i].first+b)] += dp[cur][a][b] * items[i].second / 100;
                }
                dp[1-cur][a][b] += dp[cur][a][b] * (100 - items[i].second) / 100;
            }
        }
        cur = 1 - cur;
    }
    LD ret = 0;
    for (int i = l; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            ret += dp[cur][i][j];
        }
    }
    printf("%.10Lf\n", ret);

    return 0;
}