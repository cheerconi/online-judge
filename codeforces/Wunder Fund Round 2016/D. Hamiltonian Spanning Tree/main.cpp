#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
const int MAXN = 200000 + 10;
vector<int> edges[MAXN];
int dp[2][MAXN];

void dfs (int root, int par) {
    int sz = 0;
    multiset<int> table;
    for (int son : edges[root]) {
        if (son == par) continue;
        dfs (son, root);
        sz++;
        dp[1][root] += dp[0][son] + 1;
        dp[0][root] += dp[0][son] + 1;
        table.insert(dp[1][son]-dp[0][son]-1);
        if (table.size() > 2) {
            auto it = table.end();
            it--;
            table.erase(it);
        }
    }
    if (sz == 1) {
        dp[1][root] += *table.begin();
        dp[0][root] += *table.begin();
    }
    else if (sz >= 2) {
        auto it = table.begin();
        dp[1][root] += *it;
        dp[0][root] += *it;
        it++;
        dp[0][root] += *it;

    }

}

int main () {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, x, y;
    LL a, b;
    cin >> n >> a >> b;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    LL ret = 0;
    if (a == b) ret = a*(n-1);
    else if (a > b) {
        bool ez = false;
        for (int i = 1;  i <= n; i++) {
            if (edges[i].size() == n-1) {
                ez = true;
                break;
            }
        }
        if (ez) ret = b*(n-2) + a;
        else ret = b*(n-1);

    }
    else {
        dfs(1, 0);
        int b_tot = min(dp[1][1], dp[0][1]);
        ret = a*(n-1-b_tot) + b*b_tot;
    }
    cout << ret << endl;
}