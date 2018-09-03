#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 200000 + 10;

int tree[4 * MAXN];

void build(int node, int start, int end) {
    if (start == end) {
        scanf("%d", &tree[node]);
        return;
    }
    int mid = start + ((end-start)>>1);
    build(node<<1, start, mid);
    build((node<<1)|1,mid+1, end);
    tree[node] = max(tree[node<<1], tree[(node<<1)|1]);
}

int get(int node, int start, int end, int i, int j) {
    if (i > end || j < start) return INT_MIN;
    if (i <= start && end <= j) return tree[node];
    int mid = start + ((end-start)>>1);
    int ret = get(node<<1, start, mid, i, j);
    ret = max(ret, get((node<<1)|1, mid+1, end, i, j));
    return ret;
}
void update(int node, int start, int end, int pos, int val) {
    if (pos > end || pos < start) return;
    if (start == end) {
        tree[node] = val;
        return;
    }
    int mid = start + ((end-start)>>1);
    update(node<<1, start, mid, pos, val);
    update((node<<1)|1, mid+1, end, pos, val);
    tree[node] = max(tree[node<<1], tree[(node<<1)|1]);
    return;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int N, M;
    while (scanf("%d%d", &N, &M) != EOF) {
        build(1, 1, N);
        while (M--) {
            char trash, cmd;
            int i, j;
            scanf("%c%c%d%d", &trash, &cmd, &i, &j);
            if (cmd == 'Q') {
                printf("%d\n", get(1, 1, N, i, j));
            } else {
                update(1, 1, N, i, j);
            }
        }
    }



    return 0;
}