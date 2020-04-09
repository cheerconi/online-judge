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
const int MAXN = 200000 + 10;
int A[MAXN], N[MAXN];

class TheUnexpectedSwap{
public:
    int findExpectedResult(int digits, string prefN, int seed){
        A[0] = seed;
        for (int i = 1; i < digits; i++) {
            A[i] = (A[i-1] * 1009 + 10009) % 100019;
        }
        for (int i = 0; i < prefN.size(); i++) {
            N[i] = prefN[i] - '0';
        }
        for (int i = prefN.size(); i < digits; i++) {
            N[i] = N[ A[i] % i ];
        }
        LL sum = 0, tmp = 1;
        for (int i = 0; i < digits; i++) {
            sum  = (sum + tmp) % mod;
            tmp = tmp * 10 % mod;
        }
        LL ret = 0;
        tmp = 1;
        for (int i = digits-1; i >= 0; i--) {
            LL coeff = (sum - tmp + mod) % mod;
            ret = (ret + coeff * N[i] % mod * 2 % mod)% mod;
            LL tmp2 = digits-1;
            tmp2 = tmp2 * (tmp2-1) % mod;
            ret  = (ret + N[i] * tmp % mod * tmp2 % mod) % mod;
            tmp = tmp * 10 % mod;
        }
        return ret;
    }

};




int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    auto sol = TheUnexpectedSwap();
    cout << sol.findExpectedResult(10, "1", 0) << endl;






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
