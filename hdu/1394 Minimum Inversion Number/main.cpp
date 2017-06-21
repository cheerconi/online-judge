#include <iostream>
#include <memory.h>

using namespace std;

const int MAXN = 5000 + 10;
int tree[MAXN*4];
int nums[MAXN];

void update(int node, int start, int end, int val) {
    if (start > val || end < val) return;
    if (start == end) {
        tree[node]++;
        return;
    }
    int mid = start + ((end-start)>>1);
    update(node<<1, start, mid, val);
    update((node<<1)|1, mid+1, end, val);
    tree[node] = tree[node<<1] + tree[(node<<1)|1];
}

int query(int node, int start, int end, int i, int j) {
    if ( i > j) return 0;
    if (start > j || end < i) return 0;
    if (i <= start && end <= j) return tree[node];
    int mid = start + ((end-start)>>1);
    int cnt = query(node<<1, start, mid, i, j);
    cnt += query((node<<1)|1, mid+1, end, i, j);
    return cnt;

}

int main() {
//    freopen("test.txt", "r", stdin);
    int N;
    while (scanf("%d", &N) != EOF) {
        memset(tree, 0, sizeof(tree));
        int sum = 0;
        for (int n = 0; n < N; n++) {
            scanf("%d", &nums[n]);
            sum += query(1, 0, N-1, nums[n]+1, N-1);
            update(1, 0, N-1, nums[n]);
        }
        int state = sum;
        for (int n = 0; n < N; n++) {
            state = state - nums[n] + N - nums[n] - 1;
            sum = min(sum, state);
        }
        cout << sum << endl;
    }

    return 0;
}