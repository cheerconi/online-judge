#include <iostream>
#include <algorithm>
#include <limits.h>
#define leftson  (node<<1)
#define rightson ((node<<1)|1)
using namespace std;
const int MAXN = 1234567;
int tree[MAXN<<1];

void build(int node, int left, int right) {
    if (left == right) {
        scanf("%d", &tree[node]);
        return;
    }
    int mid = (left+right) >> 1;
    build(leftson, left, mid);
    build(rightson, mid+1, right);
    tree[node] = min(tree[leftson], tree[rightson]);
}
void update(int node, int left, int right, int ind, int val) {
    if (left > ind || ind > right) return;
    if (left == right && right == ind) {
        tree[node] = val;
        return;
    }
    int mid = (left+right) >> 1;
    update(leftson, left, mid, ind, val);
    update(rightson, mid+1, right, ind, val);
    tree[node] = min(tree[leftson], tree[rightson]);
}
int query(int node, int left, int right, int i, int j) {
    if (left > j || right < i) return INT_MAX;
    if (i <= left && right <= j) return tree[node];
    int mid = (left + right) >> 1;
    int ret = query(leftson, left, mid, i, j);
    ret = min(ret, query(rightson, mid+1, right, i, j));
    return ret;
}


int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    build(1, 1, n);
    int q, a, b, c;
    cin >> q;
    while (q--) {
        scanf("%d%d%d", &a, &b, &c);
        if (a == 0) {
            printf("%d\n", query(1, 1, n, b, c));
        }
        else {
            update(1, 1, n, b, c);
        }
    }

    return 0;
}