#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
const int MAXN = 1e5 + 10;
vector<int> edges[MAXN];
int k;
LL ret = 1;

void dfs(int root, int fa) {
    int cnt = 0;
    for (int son : edges[root]) {
        if (son == fa) continue;
        cnt++;
    }
    int bias = 0;
    if (fa != 0) bias = 1;
    for (int i = 1; i <= cnt; i++) {
        ret = ret * (k - i - bias) % mod;
    }
    for (int son : edges[root]) {
        if (son == fa) continue;
        dfs(son ,root);
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, a, b;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n-1; i++) {
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    ret = k;
    dfs(1, 0);
    cout << ret << endl;
    return 0;
}