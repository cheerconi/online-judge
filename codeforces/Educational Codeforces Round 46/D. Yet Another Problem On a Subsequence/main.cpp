#include <iostream>
#include <climits>
#include <memory.h>
#include <random>
#include <ctime>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
#ifdef LOCAL
    #define DEBUG(x) { cerr << "# " << #x << ": " << x << endl;}
#else
    #define DEBUG(x)
#endif
mt19937_64 mt(time(0));
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/
const int mod = 998244353;
const int MAXN = 1e3 + 10;
LL dp[MAXN], fact[MAXN], inv[MAXN];
int nums[MAXN];

LL combine(int n, int k) {
    LL ret = fact[n] * inv[k] % mod;
    ret = ret * inv[n-k] % mod;
    return ret;
}
LL power(LL base, LL p) {
    base = base % mod;
    LL ret = 1;
    while (p) {
        if (p&1) ret = base * ret % mod;
        p >>= 1;
        base = base * base % mod;
    }
    return ret;
}


/*-------------------------------------coding area end------------------------------------------*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
    #ifdef LOCAL
//        freopen("../test.txt", "r", stdin);
//        freopen("../output.txt", "w", stdout);
    #endif
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    dp[n] = 1;
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i-1] * i % mod;
    }
    inv[n] = power(fact[n], mod-2);
    for (int i = n-1; i >= 0; i--) {
        inv[i] = inv[i+1] * (i+1) % mod;
    }
    for (int i = n-1; i >= 0; i--) {
        if (nums[i] <= 0) continue;
        for (int j = i + nums[i]+1; j <= n; j++) {
            dp[i] = (dp[j]*combine(j-i-1, nums[i])%mod + dp[i]) % mod;
        }
    }
    LL ret = 0;
    for (int i = 0; i < n; i++) {
        ret = (ret + dp[i]) % mod;
    }
    cout << ret << endl;




/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
