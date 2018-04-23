#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Edge{
    int to, flow, id;
    Edge(int _to, int _flow, int _id) {
        to = _to;
        flow = _flow;
        id = _id;
    }
};
const int MAXN = 2e5 + 10;
int in[MAXN], state[MAXN], n;
vector<Edge> edges[MAXN];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int m; cin >> m;
    int a, b, c;
    for (int i = 1; i <= m; i++) {
        state[i] = -1;
        cin >> a >> b >> c;
        edges[a].push_back(Edge(b, c, i));
        edges[b].push_back(Edge(a, c, -i));
        in[a] += c;
        in[b] += c;
    }
    for (int i = 2; i < n; i++) in[i] /= 2;
    queue<int> q;
    in[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto & edge : edges[cur]) {
            if (state[abs(edge.id)] != -1) continue;
            if (edge.id > 0) state[edge.id] = 0;
            else state[-edge.id] = 1;
            in[edge.to] -= edge.flow;
            if (in[edge.to] == 0) q.push(edge.to);
        }
    }
    for (int i = 1; i <= m; i++) cout << state[i] << '\n';
    return 0;
}