#include <iostream>
#include <vector>
#define leftnode (node<<1)
#define rightnode ((node<<1)|1)
using namespace std;
const int MAXN = 200000 + 10;
bool info[MAXN<<2];
int tree[MAXN<<2];
int lft[MAXN], rght[MAXN];
vector<int> sons[MAXN];
int ind = 1;

void dfs (int root) {
    lft[root] = ind++;
    for (int son : sons[root]) {
        dfs(son);
    }
    rght[root] = ind-1;
}

void update(int node, int left, int right, int i, int j) {
    if (right < i || j < left) return;
    int mid = (left + right) >> 1;
    if (left == right) {
        tree[node] = 1 - tree[node];
        return;
    }
    if (i <= left && right <= j) {
        if (info[node]) {
            info[node] = false;
            tree[node] = (right-left+1) - tree[node];
            return;
        }
        info[node] = true;
        tree[node] = (right-left+1) - tree[node];
        return;
    }
    if (info[node]) {
        update(leftnode, left, mid, left, mid);
        update(rightnode, mid+1, right, mid+1, right);
        info[node] = false;
    }

    update(leftnode, left, mid, i, j);
    update(rightnode, mid+1, right, i, j);
    tree[node] = tree[leftnode] + tree[rightnode];
}
int query(int node, int left, int right, int i, int j) {
    if (right < i || j < left) return 0;
    if (left == right) return tree[node];
    int mid = (left + right) >> 1;
    if (i <= left && right <= j) {
        return tree[node];
    }
    if (info[node]) {
        update(leftnode, left, mid, left, mid);
        update(rightnode, mid+1, right, mid+1, right);
        info[node] = false;
    }
    int ret = query(leftnode, left, mid, i, j);
    ret += query(rightnode, mid+1, right, i, j);
    return ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, val;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &val);
        sons[val].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &val);
        if(val == 1) update(1, 1, n, lft[i], lft[i]);
    }

    char s[10];
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        scanf("%s%d", s, &val);
        if (s[0] == 'g') {
            printf("%d\n", query(1, 1, n, lft[val], rght[val]));
        }
        else {
            update(1, 1, n, lft[val], rght[val]);
        }
    }
    return 0;
}