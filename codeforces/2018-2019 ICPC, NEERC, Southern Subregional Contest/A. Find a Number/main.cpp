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
const int MAXD = 500;
const int MAXS = 5000 + 10;
struct Item{
    pii pre;
    int digit = -1;
};
Item dp[MAXD][MAXS];




int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int d, s; cin >> d >> s;
    dp[0][0].pre = {-1, -1};
    dp[0][0].digit = 0;
    queue<pii> q;
    q.emplace(0, 0);
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int i = 0; i <= 9 && i+cur.second <= s; i++) {
            int x = (cur.first * 10 + i) % d;
            int y = cur.second + i;
            if (dp[x][y].digit != -1) continue;
            dp[x][y].pre = cur;
            dp[x][y].digit = i;
            q.emplace(x, y);
        }
    }
    if (dp[0][s].digit == -1) {
        cout << -1 << endl;
        return 0;
    }
    string ret;
    auto cur = dp[0][s];
    while (cur.pre.first != -1) {
        ret.push_back(cur.digit + '0');
        cur = dp[cur.pre.first][cur.pre.second];
    }
    reverse(ret.begin(), ret.end());
    cout << ret << endl;





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
