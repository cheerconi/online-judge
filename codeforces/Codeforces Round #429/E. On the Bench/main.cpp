#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 310;
const int mod = 1e9 + 7;
int factor[MAXN];
int inv[MAXN];
int n;

int power(int base, int n) {
    int ret = 1;
    int cur = base;
    while (n) {
        if(n & 1) ret = 1LL * ret * cur % mod;
        cur = 1LL * cur * cur % mod;
        n >>= 1;
    }
    return ret;
}
void init() {
    factor[0] = 1;
    for (int i = 1; i <= n; i++) {
        factor[i] = 1LL * factor[i-1] * i % mod;
    }
    for (int i = 0; i <= n; i++) {
        inv[i] = power(factor[i], mod-2);
    }
}

int combine(int n, int k) {
    if (n == 0 || k == 0) return 1;
    int ret = 1LL * factor[n] * inv[k] % mod;
    ret = 1LL * ret * inv[n-k] % mod;
    return ret;
}


LL solve(vector<int> & group) {
    init();
    vector<LL> dp(group[0], 0);
    dp[group[0]-1] = 1;
    for (int i = 1; i < group.size(); i++) {
        vector<LL> cur(dp.size()+group[i], 0);
        for (int j = 0; j < dp.size(); j++) {
            if (dp[j] == 0) continue;
            for (int k = 1; k <= min(group[i], (int)dp.size()+1); k++) {
                for (int t = 0; t <= min(j, k); t++) {
                    int not_bad = (int)dp.size() - j + 1;
                    if (not_bad < k-t) continue;
                    int state = j - t + (group[i]-k);
                    LL tmp = 1LL * combine(not_bad, k-t) * combine(j, t) % mod;
                    tmp = 1LL * tmp * combine(group[i]-1, k-1) % mod;
                    cur[state] = (cur[state] +  tmp * dp[j]) % mod;
                }
            }
        }
        cur.swap(dp);
    }
    return dp[0];

}

int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d", &n);
    map<int, int> table;
    int tmp;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        for (int i = 2; i*i <= tmp; i++) {
            while (tmp % (i*i) == 0) {
                tmp /= (i*i);
            }
        }
        table[tmp]++;

    }

    vector<int> group;
    for (auto & item : table) {
        group.push_back(item.second);
    }
    LL ret = solve(group);
    for (int num : group) {
        ret = ret * factor[num] % mod;
    }
    cout << ret << endl;

}