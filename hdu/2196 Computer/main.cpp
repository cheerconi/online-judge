#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static const int MAXN = 10000 + 10;

struct TreeNode{
    vector<int> sons;
    int cable = 0;
    int dis1 = 0;
    int dis2 = 0;
    int outer = 0;
} trees[MAXN];

void dfs(int root) {
    int dis1 = 0, dis2 = 0;
    for (int i = 0; i < trees[root].sons.size(); i++) {
        int son = trees[root].sons[i];
        dfs(son);
        int dis = trees[son].dis1 + trees[son].cable;
        if (dis > dis1) {
            dis2 = dis1;
            dis1 = dis;
        }
        else if (dis > dis2) {
            dis2 = dis;
        }
    }
    trees[root].dis1 = dis1;
    trees[root].dis2 = dis2;
}
void dp(int root) {
    for (int i = 0; i < trees[root].sons.size(); i++) {
        int id = trees[root].sons[i];
        int tmp = trees[root].dis1;
        if (trees[root].dis1 == trees[id].dis1 + trees[id].cable) tmp = trees[root].dis2;
        trees[id].outer = max(trees[root].outer, tmp) + trees[id].cable;
        dp(id);
    }
}
int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            trees[i].sons.clear();
            trees[i].dis1 = 0;
            trees[i].dis2 = 0;
            trees[i].outer = 0;
        }
        int id, cable;
        for (int i = 2; i <= n; i++) {
            scanf("%d%d", &id, &cable);
            trees[id].sons.push_back(i);
            trees[i].cable = cable;
        }
        dfs(1);
        dp(1);
        for (int i = 1; i <= n; i++) {
            printf("%d\n", max(trees[i].dis1, trees[i].outer));
        }


    }
    return 0;
}