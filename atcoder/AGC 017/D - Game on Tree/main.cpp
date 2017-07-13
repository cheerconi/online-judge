#include <iostream>
#include <vector>
using namespace std;
static const int MAXN = 100000 + 10;

struct TreeNode{
    vector<int> sons;
} trees[MAXN];

int dfs(int root, int fa) {
    int val = 0;
    for (int son : trees[root].sons) {
        if (son == fa) continue;
        val ^= (dfs(son, root) + 1);
    }
    return val;

}

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int x, y;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        trees[x].sons.push_back(y);
        trees[y].sons.push_back(x);
    }
    int val = dfs(1, 0);
    if (val != 0) {
        cout << "Alice" << endl;
    }
    else cout << "Bob" << endl;



    return 0;
}