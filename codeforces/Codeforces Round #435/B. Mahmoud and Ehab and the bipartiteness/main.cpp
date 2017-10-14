#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
vector<int> edges[MAXN];
LL cnt[2];

void dfs(int root, int fa, int id) {
    cnt[id]++;
    for (int son : edges[root]) {
        if (son == fa) continue;
        dfs(son, root, 1-id);
    }
}


int main() {
//    freopen("test.txt", "r", stdin);
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n-1; i++) {
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1, 0, 0);
    LL ret = cnt[0]*cnt[1] - (n - 1);
    cout << ret << endl;

    return 0;
}