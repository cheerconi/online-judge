#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 60 + 5;
const int mod = 1e9 + 7;
int dp[MAXN][MAXN][MAXN][MAXN];
int nums[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
    }
    sort(nums+1, nums+1+n);
    dp[0][1][0][1] = 1;
    nums[0] = nums[1];
    int k = 1, i = 2;
    while (i <= n && nums[i] == nums[i-1]) k++,i++;
    for (int j = 2; i <= n; i++,j++) {
        nums[j] = nums[i];
    }
    n = n - k + 1;
    LL ret = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            for (int u = 0; u <= n; u++) {
                for (int v = u+1; v <= n; v++) {
                    if (dp[i][j][u][v] == 0) continue;
                    int z = max(j, v) + 1;
                    if (z == n+1) {
                        ret = (ret + dp[i][j][u][v]) % mod;
                        continue;
                    }
                    if (nums[i]+nums[z] >= 2*nums[j]) {
                        dp[j][z][u][v] = (dp[i][j][u][v] + dp[j][z][u][v]) % mod;
                    }
                    if (nums[u]+nums[z] >= 2*nums[v]) {
                        dp[i][j][v][z] = (dp[i][j][u][v] + dp[i][j][v][z]) % mod;
                    }
                }
            }
        }
    }
    LL times = 1;
    while (k > 1) {
        times = times * k % mod;
        k--;
    }
    ret = ret*times % mod;
    cout << ret << endl;

    return 0;
}