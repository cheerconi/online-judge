#include <algorithm>
#include <iostream>
#include <vector>
#define leftnode (node<<1)
#define rightnode ((node<<1)|1)
#define getmid ((left+right)>>1)
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 500000 + 10;
int n, dad[MAXN], son[MAXN];
pii tree[MAXN<<2];
bool vis[MAXN];
vector<int> idx;
void build (int node, int left, int right) {
    if (left == right) {
        tree[node] = {son[left], left};
        return;
    }
    int mid = getmid;
    build (leftnode, left, mid);
    build (rightnode, mid+1, right);
    tree[node] = max(tree[leftnode], tree[rightnode]);
}
void update(int node, int left, int right, int i) {
    if (i < left || right < i) return;
    if (left == right) {
        tree[node] = {0, left};
        return;
    }
    int mid = getmid;
    update (leftnode, left, mid, i);
    update (rightnode, mid+1, right, i);
    tree[node] = max(tree[leftnode], tree[rightnode]);
}
pii query(int node, int left, int right, int i, int j) {
    if (j < left || right < i) return {-1, -1};
    if (i <= left && right <= j) return tree[node];
    int mid = getmid;
    return max(query(leftnode, left, mid, i, j), query(rightnode, mid+1, right, i, j));
}
void dfs(int cur) {
    vis[cur] = true;
    update(1, 1, n, cur);
    if (son[cur] != n+1 && !vis[son[cur]]) dfs(son[cur]);
    while (true) {
        auto item = query(1, 1, n, 1, dad[cur]-1);
        if (item.first > cur) dfs(item.second);
        else break;
    }
    idx.push_back(cur);
}

int main () {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> dad[i];
    }
    fill(son+1, son+n+1, n+1);
    for (int i = 1; i <= n; i++) {
        if (dad[i] == -1) {
            dad[i] = n + 1;
        }
        else {
            son[dad[i]] = i;
        }
    }
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }
    int cur = 1;
    vector<int> ret(n+1, 0);
    for (int i = 0; i < n; i++) {
        ret[idx[i]] = cur++;
    }
    for (int i = 1; i <= n; i++) {
        cout << ret[i];
        if (i == n) cout << endl;
        else cout << ' ';
    }
}