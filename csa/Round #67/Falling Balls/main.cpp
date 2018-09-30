#include <iostream>
#include <vector>
#define leftnode (node<<1)
#define rightnode ((node<<1)|1)
#define getmid ((left+right)>>1)
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 1e5 + 10;
int tree[MAXN<<2], n;
vector<pii> edges[MAXN];
void build (int node, int left, int right) {
    if (left == right) {
        tree[node] = left;
        return;
    }
    int mid = getmid;
    build (leftnode, left, mid);
    build (rightnode, mid+1, right);

}

void update(int node, int left, int right, int i, int j, int val) {
    if (right < i || j < left) return;
    if (i <= left && right <= j) {
        tree[node] = val;
        return;
    }
    int mid = getmid;
    if (tree[node] != 0) {
        update(leftnode, left, mid, left, mid, tree[node]);
        update(rightnode, mid+1, right, mid+1, right, tree[node]);
        tree[node] = 0;
    }
    update(leftnode, left, mid, i, j, val);
    update(rightnode, mid+1, right, i, j, val);
}

int query(int node, int left, int right, int i) {
    if (tree[node] != 0) return tree[node];
    int mid = getmid;
    if (i <= mid) return query(leftnode, left, mid, i);
    return query(rightnode, mid+1, right, i);
}

void solve (int a, int b, int val) {
    int left = 1, right = n;
    while (left < right) {
        int mid = getmid;
        int tmp = query(1, 1, n, mid);
        if (tmp >= a) right = mid;
        else left = mid+1;
    }
    a = left;
    left = 1, right = n;
    while (left < right) {
        int mid = (left+right+1) >> 1;
        int tmp = query(1, 1, n, mid);
        if (tmp >= b) right = mid - 1;
        else left = mid;
    }
    b = left;
    if (a > b) return;
    update(1, 1, n, a, b, val);
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m, a, b, c;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (a == b) continue;
        edges[c].push_back({a, b});
    }
    n = 1e5;
    build (1, 1, n);
    for (int i = n; i >= 1; i--) {
        for (auto & item : edges[i]) {
            int mid = (item.first + item.second) >> 1;
            solve (item.first, mid+1, item.first);
            solve (mid+1, item.second+1, item.second);
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> c;
        cout << query(1, 1, n, c) << '\n';
    }

}