#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static const int MAXN = 1000 + 10;

struct Soldier {
    int dpcost;
    vector<int> mycost;
    vector<int> sons;
    void init() {
        dpcost = 0;
        mycost.clear();
        sons.clear();
    }
} enemies[MAXN];

int m;
bool dfs(int root, int fa, int max) {
    int dp0cost = m+1;
    int dp1cost = -1;
    bool flag = false;
    for (int i = 0; i < enemies[root].sons.size(); i++) {
        int son = enemies[root].sons[i];
        if (son == fa) {
            dp1cost = enemies[root].mycost[i];
            if (dp1cost > max) dp1cost = -1;
            continue;
        }
        if (!dfs(son, root, max) || dp0cost == -1) {
            dp0cost = -1;
            continue;
        }
        if (!flag){
            dp0cost = 0;
            flag = true;
        }
        dp0cost += enemies[son].dpcost;
    }
    if (dp0cost > m) dp0cost = -1;
    if (dp0cost == -1 && dp1cost == -1) return false;
    if (dp0cost == -1) enemies[root].dpcost = dp1cost;
    else if (dp1cost == -1) enemies[root].dpcost = dp0cost;
    else enemies[root].dpcost = min(dp0cost, dp1cost);
    return true;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    while(scanf("%d%d", &n, &m) && n != 0) {
        for (int i = 1; i <= n; i++) enemies[i].init();
        int a, b, cost, maxcost = 0;
        for (int i = 2; i <= n; i++) {
            scanf("%d%d%d", &a, &b, &cost);
            enemies[a].sons.push_back(b);
            enemies[a].mycost.push_back(cost);
            enemies[b].sons.push_back(a);
            enemies[b].mycost.push_back(cost);
            maxcost = max(maxcost, cost);
        }
        int right = min(m, maxcost);
        int left = 0;
        while (left < right) {
            int mid = (left+right) >> 1;
            if (dfs(1, 0, mid)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        if (dfs(1, 0, left)) cout << left << endl;
        else cout << -1 << endl;


    }
    return 0;
}