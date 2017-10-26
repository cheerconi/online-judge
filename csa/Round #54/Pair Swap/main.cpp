#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
#define leftnode (node<<1)
#define rightnode ((node<<1)|1)


const int MAXN = 1e5 + 10;
int tree[MAXN << 2];
int nums[MAXN];
int ind = 1;

void build(int node, int left, int right) {
    if (left == right) {
        scanf("%d", &tree[node]);
        nums[ind++] = tree[node];
        return;
    }
    int mid = (left+right) >> 1;
    build(leftnode, left, mid);
    build(rightnode, mid+1, right);
    tree[node] = min(tree[leftnode], tree[rightnode]);
}

int find(int node, int left, int right, int i, int j) {
    if (right < i || j < left) return INT_MAX;
    if (i <= left && right <= j) return tree[node];
    int mid = (left + right) >> 1;
    int ret = find(leftnode, left, mid, i, j);
    ret = min(ret, find(rightnode, mid+1, right, i, j));
    return ret;
}

void solve(int n, int k) {
    int target;
    for (int i = 1; i < n; i++) {
        target = find(1, 1, n, i+1, min(n, i+k));
        if (target < nums[i]) {
            for (int j = min(n, i+k); j >= i+1 ; j--) {
                if (nums[j] == target) {
                    swap(nums[i], nums[j]);
                    return;
                }
            }
        }
    }
}


int main() {
//    freopen("test.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    build(1, 1, n);
    solve(n, k);
    for (int i = 1; i <= n; i++) {
        printf("%d", nums[i]);
        if (i == n) printf("\n");
        else printf(" ");
    }
    return 0;
}