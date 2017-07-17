#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 100000 + 10;
struct TreeNode{
    vector<int> sons;
    bool flag = false;
};
TreeNode tree[MAXN];
vector<int> seq;

int dis(int root, int fa) {
    if (root == 1) {
        tree[root].flag = true;
        seq.push_back(root);
        return 0;
    }

    int tmp = -1;
    for (int son : tree[root].sons) {
        if (son == fa) continue;
        tmp = dis(son, root);
        if (tmp != -1) {
            tree[root].flag = true;
            seq.push_back(root);
            return tmp+1;

        }
    }
    return tmp;
}
int cnt(int root, int fa) {
    int ret = 1;
    for (int son : tree[root].sons) {
        if (son == fa) continue;
        ret += cnt(son, root);
    }
    return ret;
}


int main() {
//    freopen("test.txt", "r", stdin);
    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i <= n-1; i++) {
        scanf("%d%d", &a, &b);
        tree[a].sons.push_back(b);
        tree[b].sons.push_back(a);
    }
    dis(n, n+1);
    int snu = seq.size() / 2;
    int fen = seq.size() - snu;
    vector<int> ret(2, 0);
    for (int i = 0; i < fen; i++) {
        int root = seq[i];
        ret[0]++;
        for (int son : tree[root].sons) {
            if (tree[son].flag) continue;
            ret[0] += cnt(son ,root);
        }
    }
    for (int i = 0; i < snu; i++) {
        int pos = seq.size()-1 - i;
        int root = seq[pos];
        ret[1]++;
        for (int son : tree[root].sons) {
            if (tree[son].flag) continue;
            ret[1] += cnt(son ,root);
        }

    }
    if (ret[0] > ret[1]) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;


    return 0;
}