#include <iostream>
#include <algorithm>
#define leftnode (node<<1)
#define rightnode ((node<<1)|1)
#define getmid ((left+right)>>1)
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
int tree[MAXN<<2];
LL sum[MAXN<<2], info[MAXN<<2];

void build (int node, int left, int right) {
    if (left == right) {
        tree[node] = left;
        return;
    }
    int mid = getmid;
    build (leftnode, left, mid);
    build (rightnode, mid+1, right);
}

void push(int node, int left, int right) {
    if (info[node] == 0 || left == right) return;
    int mid = getmid;
    sum[leftnode] += info[node]*(mid-left+1);
    sum[rightnode] += info[node]*(right-mid);
    info[leftnode] += info[node];
    info[rightnode] += info[node];
    tree[leftnode] = tree[rightnode] = tree[node];
    info[node] = 0;
}

void update(int node, int left, int right, int i, int j, int val) {
    if (right < i || j < left) return;
    if (i <= left && right <= j && tree[node] != 0) {
        LL tmp = abs(tree[node] - val);
        info[node] += tmp;
        sum[node] += tmp*(right-left+1);
        tree[node] = val;
        return;
    }
    push(node, left, right);
    int mid = getmid;
    update(leftnode, left, mid, i, j, val);
    update(rightnode, mid+1, right, i, j, val);
    if (tree[leftnode] == tree[rightnode]) tree[node] = tree[leftnode];
    else tree[node] = 0;
    sum[node] = sum[leftnode] + sum[rightnode];
}
LL query(int node, int left, int right, int i, int j) {
    if (right < i || j < left) return 0;
    if (i <= left && right <= j) {
        return sum[node];
    }
    push(node, left, right);
    int mid = getmid;
    LL ret = query(leftnode, left, mid, i, j);
    ret += query(rightnode, mid+1, right, i, j);
    return ret;
}



int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, a, b, c, cmd;
    cin >> n >> m;
    build (1, 1, n);
    for (int i = 0; i < m; i++) {
        cin >> cmd >> a >> b;
        if (cmd == 1) {
            cin >> c;
            update(1, 1, n, a, b ,c);
        }
        else cout << query(1, 1, n, a, b) << '\n';
    }

    return 0;
}