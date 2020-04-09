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
LL x[7];





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int T, W; cin >> T >> W;
    for (int cs = 1; cs <= T; cs++) {
        memset(x, 0, sizeof(x));
        cout << 200 << endl;
        LL tot = 0;
        cin >> tot;
        if (tot == -1) return 0;
        LL val = 1LL<<50;
        while (tot >= val) {
            tot -= val;
            x[4]++;
        }
        val = 1LL<<40;
        while (tot >= val) {
            tot -= val;
            x[5]++;
        }
        val = 1LL<<33;
        while (tot >= val) {
            tot -= val;
            x[6]++;
        }
        assert(tot == 0);
        cout << 54 << endl;
        LL bias = x[4] * (1LL<<13) + x[5] * (1LL<<10) + x[6] * (1LL<<9);
        cin >> tot;
        if (tot == -1) return 0;
        tot -= bias;
        val = 1LL<<54;
        while (tot >= val) {
            tot -= val;
            x[1]++;
        }
        val = 1LL<<27;
        while (tot >= val) {
            tot -= val;
            x[2]++;
        }
        val = 1LL<<18;
        while (tot >= val) {
            tot -= val;
            x[3]++;
        }
        assert(tot == 0);
        for (int i = 1; i <= 6; i++) {
            cout << x[i];
            if (i == 6) cout << endl;
            else cout << ' ';
        }
        cin >> tot;
        assert(tot == 1);
    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
