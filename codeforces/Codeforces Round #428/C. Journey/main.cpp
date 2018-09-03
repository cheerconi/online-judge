#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 100000 + 10;
vector<int> sons[MAXN];
double p[MAXN];
int dis[MAXN];
double ret = 0;

void dfs(int root, int fa) {
    dis[root] = dis[fa] + 1;
    int child = sons[root].size() - 1;
    if (child == 0) {
        ret += dis[root] * p[root];
        return;
    }
    double tmp = 1.0 / child * p[root];
    for (int son : sons[root]) {
        if (son == fa) continue;
        p[son] = tmp;
        dfs(son, root);
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        sons[a].push_back(b);
        sons[b].push_back(a);
    }
    dis[0] = -1;
    p[1] = 1.0;
    sons[1].push_back(0);
    dfs(1, 0);
    printf("%.10f\n", ret);
    return 0;
}