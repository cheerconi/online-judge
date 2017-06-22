#include <iostream>
#include <stdio.h>

#define LL long long
#define getmid start + ((end-start)>>1)
#define leftnode node<<1
#define rightnode (node<<1)|1

const int MAXN = 100000 + 10;

LL tree[MAXN<<2];
LL info[MAXN<<2];

void build(int node, int start, int end) {
    info[node] = 0;
    if (start == end) {
        scanf("%lld", &tree[node]);
        return;
    }
    int mid = getmid;
    build(leftnode, start, mid);
    build(rightnode, mid+1, end);
    tree[node] = tree[leftnode] + tree[rightnode];
    return;
}

void update(int node, int start, int end, int i, int j, int val) {
    if (i > end || j < start) return;
    if (i <= start && end <= j) {
        info[node] += val;
        tree[node] += (LL)val * (end-start+1);
        return;
    }
    int mid = getmid;
    if (info[node]) {
        update(leftnode, start, mid, start, mid, info[node]);
        update(rightnode, mid+1, end, mid+1, end, info[node]);
        info[node] = 0;
    }
    update(leftnode, start, mid, i, j, val);
    update(rightnode, mid+1, end, i, j, val);
    tree[node] = tree[leftnode] + tree[rightnode];
    return;


}
LL query(int node, int start, int end, int i, int j) {
    if (i > end || j < start) return 0;
    if (i <= start && end <= j) return tree[node];
    int mid = getmid;
    if (info[node]) {
        update(leftnode, start, mid, start, mid, info[node]);
        update(rightnode, mid+1, end, mid+1, end, info[node]);
        info[node] = 0;
    }
    LL cnt = query(leftnode, start, mid, i, j) + query(rightnode, mid+1, end, i, j);
//    tree[node] = tree[leftnode] + tree[rightnode];
    return cnt;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int N,Q;
    scanf("%d%d", &N, &Q);
    build(1, 1, N);
    char c,trash;
    int i, j, val;
    for (int q = 0; q < Q; q++) {
        scanf("%c%c", &trash, &c);
        if (c == 'Q') {
            scanf("%d%d", &i, &j);
            printf("%lld\n", query(1, 1, N, i, j));
        }
        else {
            scanf("%d%d%d", &i, &j, &val);
            update(1, 1, N, i, j, val);
        }
    }
    return 0;
}