#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long double LD;
typedef long long LL;


const int MAXN = 65;
int nums[MAXN];
vector<int> primes;
int dp[MAXN];
vector<LL> vals[MAXN];

void make_primes() {
    for (int i = 2; i < MAXN; i++) {
        if (nums[i] == 1) continue;
        for (int j = i+i; j < MAXN; j += i) {
            nums[j] = 1;
        }
    }
    for (int i = 2; i < MAXN; i++) {
        if (nums[i] == 1) continue;
        primes.push_back(i);
    }
}

void dfs(int i, int cur, int cnt) {
    if (cur >= 63) return;
    if (i == primes.size()) {
        if (cnt % 2 == 0) dp[cur] = 1;
        else dp[cur] = -1;
        return;
    }
    dfs(i+1, cur*primes[i], cnt+1);
    dfs(i+1, cur, cnt);
}

LL multi(LL a, LL b) {
    LD tmp = (LD)a*b;
    if (tmp > 1e18) return -1;
    return a*b;
}

LL power(LL base, LL p) {
    LL ret = 1;
    while (p) {
        if (base < 0) return -1;
        if (p & 1) {
            ret = multi(ret, base);
            if (ret < 0) return -1;
        }
        base = multi(base, base);
        p >>= 1;
    }
    return ret;
}

LL solve(LL val) {
    LL b;
    LL ret = val - 1;
    for (int i = 2; i < 63; i++) {
        if ((1LL<<i) > val) break;
        if (dp[i] == 0) continue;
        if (i == 2) {
            b = sqrt((LD)val);
        }
        else if (i == 3) {
            b = cbrt((LD)val);
        } else {
            int idx = upper_bound(vals[i].begin(), vals[i].end(), val) - vals[i].begin();
            idx--;
            b = idx;
        }
        ret += dp[i]*(b-1);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
#endif
    make_primes();
    dfs(0, 1, 0);
    for (int i = 5; i < MAXN; i++) {
        vals[i].push_back(0);
        vals[i].push_back(1);
        for (LL j = 2; ; j++) {
            LL tmp = power(j, i);
            if (tmp < 0 || tmp > 1e18) break;
            vals[i].push_back(tmp);
        }
    }

    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        LL val; cin >> val;
//        assert(val != 999999999999999956LL);
        cout << solve(val) << endl;
    }
    return 0;
}
