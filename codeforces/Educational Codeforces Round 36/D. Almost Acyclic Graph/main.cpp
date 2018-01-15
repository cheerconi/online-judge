#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 500 + 10;
int state[MAXN];
vector<int> edges[MAXN];
vector<pii> path;
bool dfs (int cur, bool record = false) {
    state[cur] = 1;
    for (int i = 0; i < edges[cur].size(); i++) {
        int nxt = edges[cur][i];
        if (nxt == -1 || state[nxt] == 2) continue;
        if (record) path.push_back({cur, i});
        if (state[nxt] == 0) {
            if (!dfs (nxt, record)) return false;
        }
        else {
            if (record) {
                reverse(path.begin(), path.end());
                while (path.back().first != nxt) {
                    path.pop_back();
                }
            }
            return false;
        }
        if (record) path.pop_back();
    }
    state[cur] = 2;
    return true;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (state[i] == 0 && !dfs(i, true)) break;
    }
    for (pii item : path) {
        int tmp = edges[item.first][item.second];
        edges[item.first][item.second] = -1;
        memset(state, 0, sizeof(state));
        bool succ = true;
        for (int i = 1; i <= n; i++) {
            if (state[i] == 0 && (!dfs(i))) {
                succ = false;
                break;
            }
        }
        edges[item.first][item.second] = tmp;
        if (succ) {
            cout << "YES" << endl;
            return 0;
        }
    }
    if (path.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}