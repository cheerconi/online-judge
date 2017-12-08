#include <iostream>
using namespace std;
typedef long long LL;
const int MAXN = 1000000 + 10;
int nums[MAXN], loop[MAXN], sorted[MAXN], par[MAXN];
LL loop_cost[MAXN], node_cost[MAXN], degree[MAXN];
bool vis[MAXN];
int loop_num, n, m;
bool check (LL val) {
    for (int i = 1; i <= n; i++) {
        node_cost[i] = nums[i] - val;
    }
    for (int i = 1; i <= loop_num; i++) loop_cost[i] = 0;
    LL ret = 0;
    for (int i = 1; i <= n; i++) {
        int u = sorted[i];
        if (loop[u]) {
            loop_cost[loop[u]] += node_cost[u];
            continue;
        }
        if (node_cost[u] < 0) {
            if (par[u] == -1)  ret += node_cost[u];
            else node_cost[par[u]] += node_cost[u];
        }
    }
    for (int i = 1; i <= loop_num; i++) {
        if (loop_cost[i] < 0) ret += loop_cost[i];
    }
    if (-ret > m) return false;
    return true;
}

int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &par[i]);
        if (par[i] != -1) degree[par[i]]++;
    }
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            sorted[++tot] = i;
            vis[i] = true;
        }
    }
    for (int i = 1; i <= tot; i++) {
        int u = sorted[i];
        if (par[u] != -1) {
            degree[par[u]]--;
            if (degree[par[u]] == 0) {
                sorted[++tot] = par[u];
                vis[par[u]] = true;
             }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            loop_num++;
            int cur = i;
            while (loop[cur] == 0) {
                loop[cur] = loop_num;
                vis[cur] = true;
                sorted[++tot] = cur;
                cur = par[cur];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
    }
    LL left = 0, right = 2e9;
    while (left < right) {
        LL mid = (left+right+1) >> 1;
        if (check(mid)) left = mid;
        else right = mid - 1;
    }
    cout << left << endl;
    return 0;
}