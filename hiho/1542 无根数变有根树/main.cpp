#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1000 + 10;

struct Node{
    vector<int> sons;
    int dad;
};

Node tree[MAXN];

void dfs(int root, int fa) {
    tree[root].dad = fa;
    for (int son : tree[root].sons) {
        if (son == fa) continue;
        dfs(son, root);
    }

}


int main() {
//    freopen("test.txt", "r", stdin);
    int n, root, a, b;
    scanf("%d%d", &n, &root);
    for (int i = 1; i <= n-1; i++) {
        scanf("%d%d", &a, &b);
        tree[a].sons.push_back(b);
        tree[b].sons.push_back(a);
    }
    dfs(root, 0);
    for (int i = 1; i <= n; i++) {
        printf("%d", tree[i].dad);
        if (i == n) printf("\n");
        else printf(" ");
    }


    return 0;
}