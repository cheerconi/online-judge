#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <memory.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long double LD;
typedef long long LL;
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#ifdef LOCAL
    #define DEBUG(x) { cerr << "# " << #x << ": " << x << endl;}
#else
    #define DEBUG(x)
#endif
mt19937_64 mt(time(0));
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧  
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     
　　　　／　　　＼　 　  |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
---------------------------------------------------------------------------------------------------*/
const int mod = 1e9 + 7;
const int MAXN = 1e4 + 10;
LL dp[200][MAXN];
LL inv[200];
LL p = 1;

LL power(LL base, int p) {
    base = base % mod;
    LL ret = 1;
    while (p) {
        if (p & 1) {
            ret = ret * base % mod;
        }
        base = base * base % mod;
        p >>= 1;
    }
    return ret;
}
LL solve(int x, int k) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int j = 1; j <= x; j++) {
        dp[j][0] = dp[j-1][0] * p % mod;
    }
    for (int i = 1; i <= k; i++) {
        LL sum = 0;
        for (int j = 0; j <= x; j++) {
            sum = (sum + dp[j][i-1]) % mod;
            dp[j][i] = sum * inv[j+1] % mod;
        }
    }
    return dp[x][k];
}




int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    for (int i = 1; i < 200; i++) {
        inv[i] = power(i, mod-2);
    }
    int k;
    LL val; cin >> val >> k;
    LL ret = 1;
    for (LL i = 2; i*i <= val; i++) {
        int x = 0;
        while (val % i == 0) {
            val /= i;
            x++;
        }
        if (x == 0) continue;
        p = i;
        ret = ret * solve(x, k) % mod;
    }
    if (val != 1) {
        p = val;
        ret = ret * solve(1, k) % mod;

    }
    cout << ret << endl;






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
