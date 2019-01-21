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
const int MAXN = 2e5 + 10;
const int mod = 1e9 + 7;
LL dp[MAXN][3];
int cnt[3];

void solve(int b, int coeff) {
    for (int i = 0; i < 3; i++) {
        cnt[i] += b / 3 * coeff;
        if (i == 1 && b%3 >= 1) cnt[i] += coeff;
        if (i == 2 && b%3 == 2) cnt[i] += coeff;
    }
}






int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n, a, b;
    cin >> n >> a >> b;
    solve(b, 1);
    solve(a-1, -1);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            if (dp[i-1][j] == 0) continue;
            for (int k = 0; k < 3; k++) {
                dp[i][(j+k)%3] += dp[i-1][j] * cnt[k] % mod;
                dp[i][(j+k)%3] %= mod;
            }
        }
    }
    cout << dp[n][0] << endl;







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
