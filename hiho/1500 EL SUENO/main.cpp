#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
typedef long long LL;

const LL INF = 0x2fffffffffffffff;
const int MAXN = 2000 + 10;
struct Villian {
    vector<int> sons;
    LL need;
    LL cost;
    LL info;
    LL dpval = INF;

};
Villian gang[MAXN];


void dfs(int root) {
    if (gang[root].need == 0) {
        gang[root].dpval = gang[root].cost;
        return;
    }
    for (int son : gang[root].sons) {
        dfs(son);
    }

    vector<LL> dp(gang[root].need+1, INF);
    dp[0] = 0;
    for (int son : gang[root].sons) {
        for (LL i = gang[root].need; i >= 0; i--) {
            dp[i] = min(dp[i], dp[max(i-gang[son].info, 0LL)]+gang[son].dpval);
        }
    }
    gang[root].dpval = dp[gang[root].need] + gang[root].cost;
    return;


}

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    LL fa, need, info, cost, root;
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld%lld%lld", &fa, &need, &info, &cost);
        if (fa == 0) root = i;
        gang[fa].sons.push_back(i);
        gang[i].need = need;
        gang[i].info = info;
        gang[i].cost = cost;
    }
    dfs(root);
    if (gang[root].dpval >= INF) cout << -1 << endl;
    else cout << gang[root].dpval << endl;


}