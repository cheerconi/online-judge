#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 100000 + 10;

vector<int> edges[MAXN];
int ret = 0;

int dfs(int root, int fa) {
    int cnt = 1;
    for (int son : edges[root]) {
        if (son == fa) continue;
        int tmp = dfs(son, root);
        if (tmp > 0 && tmp % 2 == 0) ret++;
        cnt += tmp;
    }
    return cnt;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1, 0);
    cout << ret << endl;

    return 0;
}