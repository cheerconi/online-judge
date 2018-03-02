#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
const int MAXN = 1e6 + 10;
const int mod = 1e9 + 7;
int nums[MAXN], res[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    LL n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<vi> dp(k, vi(n, 0));
    LL pieces = m / n;
    for (int i = 0; i < m % n; i++) {
        res[i] = nums[i];
    }
    sort(nums, nums+n);
    sort(res, res+m%n);
    for (int i = 0; i < n; i++) {
        dp[0][i] = i+1;
    }
    LL ret = m/n*n % mod;
    for (int i = 1; i < min(k, pieces); i++) {
        int idx = 0;
        for (int j = 0; j < n; j++) {
            while (idx+1 < n && nums[idx+1] <= nums[j]) idx++;
            ret = (ret + 1LL*dp[i-1][idx]*((pieces-i)%mod)%mod) % mod;
            dp[i][j] = dp[i-1][idx];
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
        }
    }
    ret = (ret + m%n) % mod;
    int idx = 0;
    for (int i = 0; i < m%n; i++) {
        while (idx+1 < n && nums[idx+1] <= res[i]) idx++;
        for (int j = 1; j < min(k, pieces+1); j++) {
            ret = (ret + dp[j-1][idx]) % mod;
        }
    }
    cout << ret << endl;
}

