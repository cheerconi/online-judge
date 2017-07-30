#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
const int MAXN = 500 + 10;

vector<int> neg[MAXN];
int dad[MAXN];


bool dfs(int root, int fa) {
    if (dad[root] != -1) return false;
    dad[root] = fa;
    for (int son : neg[root]) {
        if (son == fa) continue;
        if (!dfs(son, root)) return false;
    }
    return true;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, a, b;
        scanf("%d%d", &n, &m);
        memset(dad, -1, sizeof(dad));
        for (int i = 1; i <= n; i++) {
            neg[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &a, &b);
            neg[a].push_back(b);
            neg[b].push_back(a);
        }
        if (m != n-1) {
            cout << "NO" << endl;
            continue;
        }
        if (dfs(1, 0)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}