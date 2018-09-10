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

LL dp[4][20];
string s;

LL solve(int n, int cnt, bool bound) {
    if (cnt == 4) return 0;
    if (!bound) {
        if (dp[cnt][n] != -1) return dp[cnt][n];
    }
    if (n == 0) return 1;
    int m = 9;
    if (bound) m = s[s.size()-n] - '0';
    LL ret = 0;
    for (int i = 0; i <= m; i++) {
        if (i == 0) ret += solve(n-1, cnt, bound && (m == i));
        else ret += solve(n-1, cnt+1, bound && (m == i));
    }
    dp[cnt][n] = ret;
    return ret;
}





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int T; cin >> T;
    LL a, b;

    while (T--) {
        cin >> a >> b;
        s = to_string(a-1);
        memset(dp, -1, sizeof(dp));
        LL cnt_a = solve(s.size(), 0, true);
        s = to_string(b);
        memset(dp, -1, sizeof(dp));
        LL cnt_b = solve(s.size(), 0, true);
        cout << cnt_b - cnt_a << endl;
    }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
