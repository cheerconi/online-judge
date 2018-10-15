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
typedef pair<int, pii> piii;
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
const int MAXN = 2000 + 10;
string mat[MAXN];
int dp[MAXN][MAXN];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int r, c;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n, m; cin >> n >> m;
    cin >> r >> c;
    r--; c--;
    int x, y; cin >> x >> y;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    priority_queue<piii, vector<piii>, greater<piii> > q;
    memset(dp, -1, sizeof(dp));
    q.emplace(0, make_pair(r,c));
    dp[r][c] = 0;
    while (!q.empty()) {
        auto curs = q.top(); q.pop();
        auto cur = curs.second;
        if (dp[cur.first][cur.second] != -1 && dp[cur.first][cur.second] < curs.first) continue;
        int statex, statey;
        if (cur.second > c) {
            statey = cur.second - c + curs.first;
            statex = curs.first;
        } else {
            statex = c - cur.second + curs.first;
            statey = curs.first;
        }
        for (int k = 0; k < 4; k++) {
            int xx = dx[k] + cur.first;
            int yy = dy[k] + cur.second;
            if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            if (mat[xx][yy] == '*') continue;
            int tmpx = statex, tmpy = statey;
            if (k == 0) tmpy++;
            if (k == 1) tmpx++;
            if (tmpx > x || tmpy > y) continue;
            int cost = 0;
            if (yy >= c) cost = tmpx;
            else cost = tmpy;
            if (dp[xx][yy] != -1 && dp[xx][yy] <= cost) continue;
            dp[xx][yy] = cost;
            q.emplace(cost, make_pair(xx, yy));
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] != -1) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
