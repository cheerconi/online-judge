#include <iostream>
#include <climits>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long LL;
typedef long double LD;
const int MAXN = 55;
struct Edge{
    int rev, cap, to;
};
LD eps = 1e-9;
int iter[MAXN], level[MAXN];
vector<Edge> edges[MAXN], data[MAXN];
void add_edge(int a, int b, int c){
    Edge item;
    item.to = b; item.cap = c; item.rev = data[b].size();
    data[a].push_back(item);
    item.to = a; item.cap = 0; item.rev = data[a].size()-1;
    data[b].push_back(item);
};
bool bfs(int s, int t) {
    memset(level, -1, sizeof(level));
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto item : edges[cur]) {
            if (level[item.to] != -1 || item.cap == 0) continue;
            level[item.to] = level[cur] + 1;
            q.push(item.to);
        }
    }
    if (level[t] == -1) return false;
    memset(iter, 0, sizeof(iter));
    return true;
}
LL dfs(int cur, int t, int f) {
    if (f == 0 || cur == t) return f;
    for (int & i = iter[cur]; i < edges[cur].size(); i++) {
        auto & item = edges[cur][i];
        if (item.cap == 0 || level[item.to] != level[cur]+1) continue;
        LL tmp = dfs(item.to, t, min(f, item.cap));
        if (tmp != 0) {
            item.cap -= tmp;
            edges[item.to][item.rev].cap += tmp;
            return tmp;
        }
    }
    return 0;
}
LL max_flow(int s, int t) {
    LL ret = 0;
    while (bfs(s, t)) {
        LL tmp;
        while (tmp = dfs(s, t, INT_MAX)) {
            ret += tmp;
        }
    }
    return ret;
}
bool solve (int s, int t, LD val, int x) {
    for (int i = s; i <= t; i++) {
        for (int j = 0; j < data[i].size(); j++) {
            edges[i][j].cap = (int)min(data[i][j].cap / val, (LD)x);
        }
    }
    LL f = max_flow(s, t);
    if (f >= x) return true;
    return false;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL n, m, x, a, b, c;
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        add_edge(a, b, c);
    }
    for (int i = 1; i <= n; i++) {
        edges[i] = data[i];
    }
    LL f = max_flow(1, n);
    LD left = 0, right = f;
    while (fabs(right - left) > eps) {
        LD mid = (left + right) / 2;
        if (solve (1, n, mid / x, x)) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    cout.setf(ios::fixed);
    cout << setprecision(10) << left << endl;
    return 0;


}