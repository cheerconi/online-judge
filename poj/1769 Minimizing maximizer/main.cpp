#include <iostream>
#include <algorithm>
#include <limits.h>
#define leftnode (node<<1)
#define rightnode ((node<<1)|1)
#define getmid ((left+right)>>1)
using namespace std;
const int MAXN = 50000 + 10;
int tree[MAXN<<2], info[MAXN<<2], n;
void build (int node, int left, int right) {
    if (left == right) {
        tree[node] = INT_MAX;
        info[node] = INT_MAX;
        return;
    }
    int mid = getmid;
    build(leftnode, left, mid);
    build(rightnode, mid+1, right);
    tree[node] = INT_MAX;
    info[node] = INT_MAX;
}
void update(int node, int left, int right, int i, int j, int val) {
    if (j < left || right < i) return;
    if (i <= left && right <= j) {
        info[node] = val;
        tree[node] = val;
        return;
    }
    int mid = getmid;
    if (info[node] != -1) {
        update(leftnode, left, mid, left, mid, info[node]);
        update(rightnode, mid+1, right, mid+1, right, info[node]);
        info[node] = -1;
    }
    update(leftnode, left, mid, i, j, val);
    update(rightnode, mid+1, right, i, j, val);
    tree[node] = max(tree[leftnode], tree[rightnode]);
}

int query(int node, int left, int right, int i) {
    if (info[node] != -1) return info[node];
    int mid = getmid;
    if (i <= mid) return query(leftnode, left, mid, i);
    else return query(rightnode, mid+1, right, i);
}
void solve (int a, int b) {
    int val = query(1, 1, n, a);
    int left = a, right = b;
    while (left < right) {
        int mid = (left + right + 1) >> 1;
        if (query(1, 1, n, mid) == val) {
            left = mid;
        }
        else {
            right = mid - 1;
        }
    }
    if (left+1 <= b) {
        update(1, 1, n, left+1, b, val+1);
    }
}


int main() {
//    freopen("test.txt", "r", stdin);
    int m, a, b;
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    update(1, 1, n, 1, 1, 0);
    while (m--) {
        scanf("%d%d", &a, &b);
        solve(a, b);
    }

    cout << query(1, 1, n, n) << endl;
    return 0;
}