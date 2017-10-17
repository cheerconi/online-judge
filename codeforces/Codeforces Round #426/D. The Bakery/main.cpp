#include <iostream>
#include <algorithm>
#include <limits.h>

#define leftnode (node << 1)
#define rightnode ((node<<1)|1)

using namespace std;
const int MAXN = 35000 + 10;
const int MAXK = 55;
int tree[MAXN<<2], info[MAXN<<2];
int dp[MAXK][MAXN];
int nums[MAXN];
int pre[MAXN], cur[MAXN];

void build (int node, int start, int end, int i) {
    if (start == end) {
        tree[node] = dp[i][start-1];
        info[node] = 0;
        return;
    }
    int mid = (start + end) >> 1;
    build(leftnode, start, mid, i);
    build(rightnode, mid+1, end, i);
    tree[node] = max(tree[leftnode], tree[rightnode]);
    info[node] = 0;
}
void update(int node, int start, int end, int i, int j, int val) {
    if (end < i || j < start) return;
    if (i <= start && end <= j) {
        tree[node] += val;
        info[node] += val;
        return;
    }
    int mid = (start + end) >> 1;
    if (info[node] != 0) {
        update(leftnode, start, mid, start, mid, info[node]);
        update(rightnode, mid+1, end, mid+1, end, info[node]);
        info[node] = 0;
    }
    update(leftnode, start, mid, i, j, val);
    update(rightnode, mid+1, end, i, j, val);
    tree[node] = max(tree[leftnode], tree[rightnode]);
}

int query(int node, int start, int end, int i, int j) {
    if (end < i || j < start) return INT_MIN;
    if (i <= start && end <= j) {
        return tree[node];
    }
    int mid = (start + end) >> 1;
    if (info[node] != 0) {
        update(leftnode, start, mid, start, mid, info[node]);
        update(rightnode, mid+1, end, mid+1, end, info[node]);
        info[node] = 0;
    }
    return max(query(leftnode, start, mid, i, j), query(rightnode, mid+1, end, i, j));
}


int main() {
//    freopen("test.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
        pre[i] = cur[nums[i]];
        cur[nums[i]] = i;
    }
    for (int i = 1; i <= k; i++) {
        build(1, 1, n, i-1);
        for (int j = i; j <= n; j++) {
            update(1, 1, n, pre[j]+1, j, 1);
            dp[i][j] = query(1, 1, n, 1, j);
        }
    }
    cout << dp[k][n] << endl;
}