#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
const int MAXN = 1e5 + 10;
vector<int> edges[MAXN];
vector<bool> states[MAXN];
int dp[MAXN];
vector<int> goods;

void dfs1(int root, int fa) {
    for (int son : edges[root]) {
        if (son == fa) continue;
        dfs1(son, root);
        dp[root] += dp[son];
    }
    dp[root]++;
}
void dfs2(int root, int fa) {
    for (int i = 0; i < edges[root].size(); i++) {
        if (edges[root][i] == fa) continue;
        if (states[root][i]) goods.push_back(dp[edges[root][i]]);
        else dfs2(edges[root][i], root);
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, k, a, b, c;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n-1; i++) {
        scanf("%d%d%d", &a, &b, &c);
        edges[a].push_back(b);
        edges[b].push_back(a);
        states[a].push_back(c);
        states[b].push_back(c);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    sort(goods.begin(), goods.end(), greater<int>());
    int sum = 0, cnt = 0;
    for (int num : goods) {
        if (n-k <= sum) break;
        sum += num;
        cnt++;
    }
    if (n-k > sum) cout << -1 << endl;
    else cout << cnt <<endl;





    return 0;
}