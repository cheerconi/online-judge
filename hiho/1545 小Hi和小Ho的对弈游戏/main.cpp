#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
const int MAXN = 100000 + 10;
struct Node{
    vector<int> sons;
    int dp;
};

Node tree[MAXN];

void dfs(int root) {
    int val = 0;
    for (int son : tree[root].sons) {
        dfs(son);
        val ^= (tree[son].dp+1);
    }
    tree[root].dp = val;

}

int main() {
//    freopen("test.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, a, b;
        scanf("%d", &n);
        unordered_set<int> roots;
        for (int i = 1; i <= n; i++) {
            roots.insert(i);
            tree[i].sons.clear();
        }
        for (int i = 1; i <= n-1; i++) {
            scanf("%d%d", &a, &b);
            tree[a].sons.push_back(b);
            auto it = roots.find(b);
            if (it != roots.end()) roots.erase(it);
        }
        int root = *roots.begin();
        dfs(root);
        int val = 0;
        for (int son : tree[root].sons) {
            val ^= tree[son].dp;
        }
        bool ret = tree[root].dp > 0;
        if (ret) cout << 1;
        else cout << 0;
        ret = val > 0;
        if (ret) cout << 1;
        else cout << 0;
    }
    cout << endl;
    return 0;
}