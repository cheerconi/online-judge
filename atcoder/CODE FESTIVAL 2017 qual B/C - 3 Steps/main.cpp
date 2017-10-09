#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
vector<int> edges[MAXN];
bool vis1[MAXN];
bool vis0[MAXN];
int dad[MAXN];
int n, m;

int find(int i) {
    if (dad[i] == i) return i;
    return dad[i] = find(dad[i]);
}

void add (int i, int j) {
    int a = find(i);
    int b = find(j);
    dad[max(a, b)] = min(a, b);
}

void dfs(int root, int fa, bool flag) {
    if (flag) vis1[root] = true;
    if (!flag) vis0[root] = true;
    if (flag) add(1, root);
    for (int son : edges[root]) {
        if (son == fa) continue;
        if (flag && !vis0[son]) dfs(son, root, !flag);
        if (!flag && !vis1[son]) dfs(son, root, !flag);
    }
}
int main() {
//    freopen("test.txt", "r", stdin);
    memset(vis0, false, sizeof(vis0));
    memset(vis1, false, sizeof(vis1));
    scanf("%d%d", &n, &m);
    for (int i = 1; i<= n; i++) dad[i] = i;
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(1, 0, true);

    LL cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (dad[i] == 1) cnt++;
    }
    LL ret = 0;
    if (cnt == n) {
        ret = (LL)n * (n - 1) / 2 - m;
    }
    else ret = cnt * (n-cnt) - m;
    cout << ret << endl;
    return 0;
}