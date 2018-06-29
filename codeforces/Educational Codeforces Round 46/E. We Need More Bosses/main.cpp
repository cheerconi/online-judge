#include <iostream>
#include <climits>
#include <memory.h>
#include <random>
#include <ctime>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
#ifdef LOCAL
    #define DEBUG(x) { cerr << "# " << #x << ": " << x << endl;}
#else
    #define DEBUG(x)
#endif
mt19937_64 mt(time(0));
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/
const int MAXN = 3e5 + 10;
vector<int> edges[MAXN], edges2[MAXN];
int disc[MAXN], low[MAXN], par[MAXN], dist[MAXN];
bool ins[MAXN];
stack<int> st;

void tarjan(int cur, int pre) {
    static int time = 0;
    disc[cur] = low[cur] = ++time;
    st.push(cur); ins[cur] = true;
    for (int nxt : edges[cur]) {
        if (pre == nxt) continue;
        if (disc[nxt] == 0) {
            tarjan(nxt, cur);
            low[cur] = min(low[cur], low[nxt]);
        }
        else if (ins[nxt]) {
            low[cur] = min(low[cur], low[nxt]);
        }
    }
    if (low[cur] == disc[cur]) {
        while (st.top() != cur) {
            int tmp = st.top(); st.pop();
            ins[tmp] = false;
            par[tmp] = low[cur];
        }
        st.pop();
        ins[cur] = false;
        par[cur] = low[cur];
    }
}
void remap(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j : edges[i]) {
            if (par[i] == par[j]) continue;
            edges2[par[i]].push_back(par[j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(edges2[i].begin(), edges2[i].end());
        edges2[i].resize(unique(edges2[i].begin(), edges2[i].end()) - edges2[i].begin());
    }

}

void dfs(int cur, int pre) {
    for (int nxt : edges2[cur]) {
        if (pre == nxt) continue;
        dist[nxt] = dist[cur] + 1;
        dfs(nxt, cur);
    }
}






/*-------------------------------------coding area end------------------------------------------*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
    #ifdef LOCAL
        freopen("../test.txt", "r", stdin);
//        freopen("../output.txt", "w", stdout);
    #endif
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/

    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    tarjan(1, 0);
    remap(n);
    dfs(1, 0);
    int root = 1;
    for (int i = 2; i <= n; i++) {
        if (dist[root] < dist[i]) root = i;
    }
    memset(dist, 0, sizeof(dist));
    dfs(root, 0);
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        ret = max(ret, dist[i]);
    }
    cout << ret << endl;





/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
