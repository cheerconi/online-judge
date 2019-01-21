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
const int MAXN = 1234;
string mat[MAXN];
int n, m, sp[10], ret[10];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void solve(map<int, vector<pii>>& nxt, int p, pii item) {
    queue<pii> q;
    q.push(item);
    int step = 1;
    while (!q.empty() && step <= sp[p]) {
        int sz = q.size();
        while (sz--) {
            pii cur = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                int x = cur.first + dx[k];
                int y = cur.second + dy[k];
                if (x == -1 || x == n) continue;
                if (y == -1 || y == m) continue;
                if (mat[x][y] != '.') continue;
                mat[x][y] = p + '0';
                nxt[p].emplace_back(x, y);
                q.emplace(x, y);
                ret[p]++;
            }
        }
        step++;
    }
}





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int p;
    cin >> n >> m >> p;
    for (int i = 1; i <= p; i++) {
        cin >> sp[i];
    }
    map<int, vector<pii>> table;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
        for (int j = 0; j < m; j++) {
            if (isdigit(mat[i][j])) {
                table[mat[i][j]-'0'].emplace_back(i, j);
                ret[mat[i][j]-'0']++;
            }
        }
    }
    while (!table.empty()) {
        map<int, vector<pii>> nxt;
        for (auto it = table.begin(); it != table.end(); it++) {
            for (pii item : it->second) {
                solve(nxt, it->first, item);
            }
        }
        swap(nxt, table);
    }
    for (int i = 1; i <= p; i++) {
        cout << ret[i];
        if (i == p) cout << endl;
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
