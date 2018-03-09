#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 100000 + 10;
int u[MAXN];
vector<int> edges[MAXN], v;
int state[MAXN], ret[MAXN], tag[MAXN];
bool used[MAXN];

void dfs (int cur) {
    state[cur] = 1;
    tag[cur]++;
    int cnt = 1;
    for (int nxt : edges[cur]) {
        if (state[nxt] == 0) {
            tag[nxt] = tag[cur];
            dfs (nxt);
            cnt += tag[nxt] - tag[cur];

        }
        else if (state[nxt] == 2) {
            cnt += ret[nxt];
        }
        else {
            cnt += tag[cur] - tag[nxt];

        }
    }
    state[cur] = 2;
    ret[cur] = cnt;
}
void solve (int cur) {
    used[cur] = true;
    v.push_back(cur);
    for (int nxt : edges[cur]) {
        if (used[nxt]) continue;
        solve (nxt);
    }
}




int main() {
    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, h, a, b;
    cin >> n >> m >> h;
    for (int i = 1; i <= n; i++) {
        cin >> u[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        if ((u[a]+1)%h == u[b]) {
            edges[a].push_back(b);
        }
        if ((u[b]+1)%h == u[a]) {
            edges[b].push_back(a);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ret[i] == 0) {
            dfs (i);
        }
    }
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        if (ret[idx] > ret[i]) idx = i;
    }
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i+1 == v.size()) cout << '\n';
        else cout << ' ';
    }


    return 0;
}