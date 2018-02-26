#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;
const int MAXN = 1e5 + 10;
vector<int> edges[MAXN], rev[MAXN];
int dist[2][MAXN], state[MAXN];
bool inq[MAXN];

bool dfs (int cur) {
    state[cur] = -1;
    for (int nxt : edges[cur]) {
        if (state[nxt] == 1) continue;
        if (state[nxt] == -1) return false;
        if (!dfs(nxt)) return false;
    }
    state[cur] = 1;
    return true;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, cnt, val, s;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            cin >> val;
            edges[i].push_back(val);
            rev[val].push_back(i);
        }
    }
    cin >> s;
    bool loop = !dfs(s);
    queue<int> q;
    memset(dist, -1, sizeof(dist));
    for (int i = 1; i <= n; i++) {
        if (edges[i].empty()) {
            dist[0][i] = 0;
            q.push(i);
            inq[i] = true;
        }
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop(); inq[cur] = false;
        for (int nxt : rev[cur]) {
            bool add = false;
            if (dist[0][cur] != -1) {
                if (dist[1][nxt] == -1 || dist[1][nxt] > dist[0][cur]+1) {
                    dist[1][nxt] = dist[0][cur] + 1;
                    if (!inq[nxt]) add = true;
                }
            }
            if (dist[1][cur] != -1) {
                if (dist[0][nxt] == -1 || dist[0][nxt] > dist[1][cur]+1) {
                    dist[0][nxt] = dist[1][cur] + 1;
                    if (!inq[nxt]) add = true;
                }
            }
            if (add) {
                inq[nxt] = true;
                q.push(nxt);
            }
        }
    }
    if (dist[1][s] == -1) {
        if (loop) cout << "Draw" << endl;
        else cout << "Lose" << endl;
        return 0;
    }
    int d = 1;
    vector<int> v;
    v.push_back(s);
    while (!edges[v.back()].empty()) {
        d = 1 - d;
        for (int nxt : edges[v.back()]) {
            if (dist[d][nxt]+1 == dist[1-d][v.back()]) {
                v.push_back(nxt);
                break;
            }
        }
    }
    cout << "Win" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i+1 == v.size()) cout << endl;
        else cout << ' ';
    }
    return 0;
}