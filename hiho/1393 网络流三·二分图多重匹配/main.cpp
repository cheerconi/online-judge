#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;
const int MAXN = 233;
struct Edge{
    int to, cap, rev;
};
vector<Edge> edges[MAXN];
int iter[MAXN], level[MAXN];

void add_edge (int a, int b, int cap) {
    edges[a].push_back((Edge){b, cap, (int)edges[b].size()});
    edges[b].push_back((Edge){a, 0, (int)edges[a].size()-1});
}
void bfs (int s) {
    memset(level, -1, sizeof(level));
    level[s] = 0;
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto & item : edges[cur]) {
            if (item.cap == 0 || level[item.to] != -1) continue;
            level[item.to] = level[cur]+1;
            q.push(item.to);
        }
    }
}
int dfs (int cur, int t, int f) {
    if (cur == t || f == 0) return f;
    for (int & i = iter[cur]; i < edges[cur].size(); i++) {
        int nxt = edges[cur][i].to;
        if (level[nxt] <= level[cur]) continue;
        int tmp = dfs(nxt, t, min(f, edges[cur][i].cap));
        if (tmp > 0) {
            edges[cur][i].cap -= tmp;
            edges[nxt][edges[cur][i].rev].cap += tmp;
            return tmp;
        }
    }
    return 0;
}
int max_flow(int s, int t) {
    int f = 0;
    while (true) {
        bfs(s);
        if (level[t] == -1) break;
        memset(iter, 0, sizeof(iter));
        while (true){
            int tmp = dfs(s, t, INT_MAX);
            if (tmp == 0) break;
            f += tmp;
        }
    }
    return f;
}


int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int cs; cin >> cs;
    int base = 100, s = 0, t = 232;
    while (cs--) {
        for (int i = 0; i < MAXN; i++) {
            edges[i].clear();
        }
        int n, m, val, tmp, ret = 0;
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            cin >> val;
            add_edge(base+i, t, val);
            ret += val;
        }
        for (int i = 1; i <= n; i++) {
            cin >> val;
            add_edge(s, i, val);
            cin >> val;
            for (int j = 0; j < val; j++) {
                cin >> tmp;
                add_edge(i, tmp+base, 1);
            }
        }
        if (ret == max_flow(s, t)) {
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }

    return 0;
}