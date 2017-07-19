#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
const int MAXN = 100 + 5;
int table[MAXN];
int fa[MAXN];
vector<vector<int> > matrix;
vector<int> leaves;
struct TreeNode{
    bool leaf = false;
    int grandson = -1;
    int depth = -1;
};
TreeNode forest[MAXN];

void findad(vector<int> const & vs, vector<int> const & vf) {
    int i = 0;
    int son = vs[i];
    int j = 0;
    int dad = vf[j];
    while (forest[dad].leaf) dad = vf[++j];
    while (i < vs.size() && j < vf.size()) {
        fa[son] = dad;
        forest[dad].grandson = forest[son].grandson;
        forest[dad].depth = forest[son].depth + 1;
        i++;
        if (i < vs.size()) {
            son = vs[i];
            int leaf1 = forest[vs[i-1]].grandson;
            int leaf2 = forest[son].grandson;
            int tmp = matrix[table[leaf1]][table[leaf2]];
            if (tmp != forest[vs[i-1]].depth + forest[son].depth + 2) j++;
            while (j < vf.size() && forest[vf[j]].leaf) j++;
            if (j < vf.size()) dad = vf[j];
        }
    }

}

int main() {
//    freopen("test.txt", "r", stdin);
    memset(table, -1, sizeof(table));
    memset(fa, -1, sizeof(fa));
    int n, m, k, tmp;
    scanf("%d%d%d", &n, &m, &k);
    vector<int> layer(m, 0);
    for (int i = 0; i < m; i++) scanf("%d", &layer[i]);
    vector<vector<int> > tree(m, vector<int>());
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < layer[i]; j++) {
            scanf("%d", &tmp);
            tree[i].push_back(tmp);
        }
    }
    leaves = vector<int> (k, 0);
    for (int i = 0; i < k; i++) {
        scanf("%d", &leaves[i]);
        table[leaves[i]] = i;
        forest[leaves[i]].leaf = true;
        forest[leaves[i]].grandson = leaves[i];
        forest[leaves[i]].depth = 0;
    }
    matrix = vector<vector<int> >(k, vector<int>(k, 0));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) scanf("%d", &matrix[i][j]);
    }

    for (int i = m-1; i >= 1; i--) {
        findad(tree[i], tree[i-1]);
    }
    fa[tree[0][0]] = 0;
    for (int i = 1; i <= n; i++) {
        printf("%d ", fa[i]);
    }
    cout << endl;



    return 0;
}