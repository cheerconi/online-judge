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
typedef pair<bool, bool> pbb;
string a, b;



int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    LL n, k;
    cin >> n >> k >> a >> b;
    LL ret = 0, oth = 0;
    queue<pbb> q;
    q.emplace(true, true);
    for (int i = 0; i < n; i++) {
        int sz = (int)q.size();
        while (sz--) {
            auto cur = q.front(); q.pop();
            if (cur.first && cur.second) {
                if (a[i] == b[i]) {
                    q.emplace(true, true);
                    continue;
                }
                q.emplace(true, false);
                q.emplace(false, true);
                continue;
            }
            if (cur.first) {
                q.emplace(true, false);
                if (a[i] == 'a') oth++;
                continue;
            }
            q.emplace(false, true);
            if (b[i] == 'b') oth++;
        }
        ret += min(k, (int)q.size()+oth);
        oth = min(k, oth*2);
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
