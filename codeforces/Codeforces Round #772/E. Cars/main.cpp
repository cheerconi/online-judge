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
int direction[MAXN], degree[MAXN];
vector<int> edges[MAXN];
vi relation[MAXN];

bool dfs(int i, int val) {
    if (direction[i] != 0) {
        return direction[i] == val;
    }
    direction[i] = val;
    for (int j : edges[i]) {
        if (!dfs(j, -val)) return false;
    }
    return true;
}

vector<int> solve(int n, int m) {
    for (int i = 1; i <= n; i++) {
        if (direction[i] == 0) {
            if (!dfs(i, 1)) {
                return {};
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        edges[i].clear();
    }
    for (int i = 0; i < m; i++) {
        int x = relation[i][1];
        int y = relation[i][2];
        assert(direction[x] + direction[y] == 0);
        assert(direction[x] != 0);
        if (relation[i][0] == 1 && direction[x] == -1) {
            edges[x].push_back(y);
            degree[y]++;
        } else if (relation[i][0] == 1 && direction[x] == 1) {
            edges[y].push_back(x);
            degree[x]++;
        } else if (relation[i][0] == 2 && direction[x] == -1) {
            edges[y].push_back(x);
            degree[x]++;
        } else {
            assert(relation[i][0] == 2 && direction[x] == 1);
            edges[x].push_back(y);
            degree[y]++;
        }
    }
    vector<int> ret;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        ret.push_back(cur);
        for (int nxt : edges[cur]) {
            degree[nxt]--;
            if (degree[nxt] == 0) q.push(nxt);
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
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        relation[i] = {a, b, c};
        edges[b].push_back(c);
        edges[c].push_back(b);
    }
    vi tmp = solve(n, m);
    if (tmp.size() != n) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vector<int> ret(n+1);
        for (int i = 0; i < n; i++) {
            ret[tmp[i]] = i;
        }

        for (int i = 1; i <= n; i++) {
            if (direction[i] == 1) cout << "R ";
            else cout << "L ";
            cout << ret[i] << '\n';
        }
    }









/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
