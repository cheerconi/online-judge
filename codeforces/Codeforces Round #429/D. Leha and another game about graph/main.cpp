#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 300000 + 10;
int n, m;
int d[MAXN];
vector<pii> edges[MAXN];
bool vis[MAXN];
vector<int> ret;

bool dfs(int root) {
    if (vis[root]) return false;
    vis[root] = true;
    int degree = 0;
    for (pii item : edges[root]) {
        if (dfs(item.first)) {
            degree++;
            ret.push_back(item.second);
        }
    }
    if (d[root]==-1 || degree%2 == d[root]) return false;
    return true;
}

int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    int a, b, root = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
        if (d[i] == -1) root = i;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &a, &b);
        edges[a].push_back({b, i});
        edges[b].push_back({a, i});
    }
    if (dfs(root)) cout << -1 << endl;
    else {
        cout << ret.size() << endl;
        for (int id : ret) cout << id << endl;
    }

    return 0;
}