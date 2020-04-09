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
string mat[300];
int dist[300][300];
struct Item{
    int a, b, c;
    bool operator< (const Item& rhs) const {
        return c > rhs.c;
    }
};
Item items[90000];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int solve_one(int tot, int x, int y) {
    int b = items[0].c;
    int a = 0;
    for (int i = 0; i < tot && a < b; i++) {
        a = max(a, min(items[i].c, abs(items[i].a-x)+abs(items[i].b-y)));
        b = items[i].c;
    }
    return a;
}

int solve(int n, int m) {
    queue<pii> q;
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '1') {
                q.emplace(i, j);
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int x = dx[k] + cur.first;
            int y = dy[k] + cur.second;
            if (dist[x][y] != -1) continue;
            dist[x][y] = dist[cur.first][cur.second] + 1;
            q.emplace(x, y);
        }
    }
    int tot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == 0) continue;
            items[tot].a = i;
            items[tot].b = j;
            items[tot].c = dist[i][j];
            tot++;
        }
    }
    if (tot == 0) return 0;
    sort(items, items+tot);
    int ret = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == 0) continue;
            ret = min(ret, solve_one(tot, i, j));
        }
    }
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
    int n, m;
    for (int cs = 1; cs <= T; cs++) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> mat[i];
        }
        cout << "Case #" << cs << ": " << solve(n, m) << endl;

    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
