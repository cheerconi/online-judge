#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
const int MAXN = 100000 + 10;
bool isroot[MAXN];
vector<int> edges[MAXN];
int cnt, L[MAXN], R[MAXN], sz[MAXN];
void dfs (int root) {
    L[root] = root;
    R[root] = root;
    sz[root] = 1;
    for (int son : edges[root]) {
        dfs(son);
        L[root] = min(L[root], L[son]);
        R[root] = max(R[root], R[son]);
        sz[root] += sz[son];
    }
    if (R[root]-L[root]+1 == sz[root]) cnt++;
}

int main() {
    memset(isroot, true, sizeof(isroot));
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n-1; i++) {
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
        isroot[b] = false;
    }
    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (isroot[i]) {
            root = i;
            break;
        }
    }
    dfs (root);
    cout << cnt << endl;

    return 0;
}