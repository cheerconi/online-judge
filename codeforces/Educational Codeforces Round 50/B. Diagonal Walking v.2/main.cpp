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
LL solve(LL a, LL b, LL k) {
    LL tmp = a + k;
    LL x1, x2;
    int cnt = 0;
    if (tmp % 2 == 1) {
        cnt++;
        x1 = tmp / 2;
        x2 = k - 1 - x1;
    } else {
        x1 = tmp / 2;
        x2 = k - x1;
    }
    if (x1 < 0 || x2 < 0) return -1;
    tmp = b + k;
    if (tmp % 2 == 1) {
        cnt++;
        x1 = tmp / 2;
        x2 = k - 1 - x1;
    } else {
        x1 = tmp / 2;
        x2 = k - x1;
    }
    if (x1 < 0 || x2 < 0) return -1;
    k -= cnt;
    if (k < 0) return -1;
    return k;
}





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int q; cin >> q;
    while (q--) {
        LL a, b, k;
        cin >> a >> b >> k;
        cout << solve(a, b, k) << endl;
    }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
