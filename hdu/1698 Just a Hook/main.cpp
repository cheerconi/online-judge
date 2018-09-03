#include <iostream>
#include <algorithm>
using namespace std;


#define leftnode  node<<1
#define rightnode  (node<<1)|1
#define getmid start + ((end-start)>>1)


const int MAXN = 100000 + 10;
int tree[MAXN<<2];




void build(int node, int start, int end) {
    tree[node] = 1;
    if(start == end) return;
    int mid = getmid;
    build(leftnode, start, mid);
    build(rightnode, mid+1, end);
    return;
}

void update(int node, int start, int end, int i, int j, int val) {
    if (i > end || j < start || tree[node] == val) return;
    if (i <= start && end <= j) {
        tree[node] = val;
        return;
    }
    int mid = getmid;
    if (tree[node] != -1) {
        tree[leftnode] = tree[node];
        tree[rightnode] = tree[node];
        tree[node] = -1;
    }
    update(leftnode, start, mid, i, j, val);
    update(rightnode, mid+1, end,i, j, val);
}

int sum(int node, int start, int end) {
    if (tree[node] != -1) return tree[node]*(end-start+1);
    int mid = getmid;
    int cnt = sum(leftnode, start, mid);
    cnt += sum(rightnode, mid+1, end);
    return cnt;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int C,N,Q,i,j,val;
    scanf("%d", &C);
    for(int c = 1; c <= C; c++) {
        scanf("%d%d", &N, &Q);
        build(1, 0, N-1);
        for (int q = 0; q < Q; q++) {
            scanf("%d%d%d",&i, &j, &val);
            update(1, 0, N-1, i-1, j-1, val);
        }
        printf("Case %d: The total value of the hook is %d.\n", c, sum(1, 0, N-1));


    }
    return 0;
}