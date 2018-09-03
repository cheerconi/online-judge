#include <iostream>
#include <algorithm>
#include <limits.h>

#define leftnode (node<<1)
#define rightnode ((node<<1)|1)
#define mid ((left+right)>>1)

using namespace std;
const int MAXN = 123456;
int tree[MAXN<<2];
int info[MAXN<<2];

void build(int node, int left, int right) {
    if (left == right) {
        scanf("%d", &tree[node]);
        return;
    }
    build(leftnode, left, mid);
    build(rightnode, mid+1, right);
    tree[node] = tree[leftnode]+tree[rightnode];
}

void update(int node, int left, int right, int i, int j, int val) {
    if (right < i || j < left) return;
    if (i <= left && right <= j) {
        tree[node] = val * (right-left+1);
        info[node] = val;
        return;
    }
    if (info[node] != 0) {
        update(leftnode, left, mid, left, mid, info[node]);
        update(rightnode, mid+1, right, mid+1, right, info[node]);
        info[node] = 0;
    }
    update(leftnode, left, mid, i, j, val);
    update(rightnode, mid+1, right, i, j, val);
    tree[node] = tree[leftnode]+tree[rightnode];
}

int query(int node, int left, int right, int i, int j) {
    if (right < i || j < left) return 0;
    if (i <= left && right <= j) {
        return tree[node];
    }
    if (info[node] != 0) {
        update(leftnode, left, mid, left, mid, info[node]);
        update(rightnode, mid+1, right, mid+1, right, info[node]);
        info[node] = 0;
    }
    int ret = query(leftnode, left, mid, i, j);
    ret += query(rightnode, mid+1, right, i, j);
    return ret;
}


int main() {
//    freopen("test.txt", "r", stdin);
    int n, q;
    cin >> n;
    build(1, 1, n);
    cin >> q;
    int a, b, c, d;
    while (q--) {
        scanf("%d", &a);
        if (a == 0) {
            scanf("%d%d", &b, &c);
            printf("%d\n", query(1, 1, n, b, c));
        }
        else {
            scanf("%d%d%d", &b, &c, &d);
            update(1, 1, n, b, c, d);
        }
    }
    return 0;
}