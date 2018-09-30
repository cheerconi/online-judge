#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;


const int MAXN = 200000 + 10;
int tree[MAXN*4];

int search(int node, int start, int end, int width) {
    if (tree[node] < width) return -1;
    if (start == end) {
        tree[node] -= width;
        return start;
    }
    int mid = start + ((end-start)>>1);
    int ret = search(node<<1, start, mid, width);
    if (ret == -1) ret = search((node<<1)|1, mid+1, end, width);
    tree[node] = max(tree[node<<1], tree[(node<<1)|1]);
    return ret;
 }
void build(int node, int start, int end, int w) {
    if (start == end) {
        tree[node] = w;
        return;
    }
    tree[node] = w;
    int mid = start + ((end-start)>>1);
    build(node<<1, start, mid, w);
    build((node<<1)|1, mid+1, end, w);
}

int main() {
//    freopen("test.txt", "r", stdin);
    int h,w,N,tmp;
    while (scanf("%d%d%d", &h, &w, &N) != EOF){
        h = min(h, N);
        build(1, 1, h, w);
        for(int n = 0; n < N; n++) {
            scanf("%d", &tmp);
            printf("%d\n", search(1, 1, h, tmp));
        }
    }
    return 0;
}