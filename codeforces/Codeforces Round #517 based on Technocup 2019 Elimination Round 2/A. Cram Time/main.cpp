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
vector<int> ret[2];
LL a, b;

void solve(int x) {
    if (a > b) {
        ret[0].push_back(x);
        a -= x;
    } else {
        ret[1].push_back(x);
        b -= x;
    }
}





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif

    cin >> a >> b;
    LL n = 0;
    while (n*(n+1)/2 <= (a+b)) {
        n++;
    }
    n--;
    for (int i = n; i >= 1; i--) {
        solve(i);
    }
    cout << ret[0].size() << endl;
    for (int i = (int)ret[0].size()-1;  i >= 0; i--) {
        cout << ret[0][i];
        if (i == 0) cout << endl;
        else cout << ' ';
    }
    cout << ret[1].size() << endl;
    for (int i = (int)ret[1].size()-1;  i >= 0; i--) {
        cout << ret[1][i];
        if (i == 0) cout << endl;
        else cout << ' ';
    }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
