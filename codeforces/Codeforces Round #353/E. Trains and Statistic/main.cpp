#include <iostream>
#include <algorithm>
#define leftnode (node<<1)
#define rightnode ((node<<1)|1)
#define getmid ((left+right)>>1)
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;
int tree[MAXN<<2], nums[MAXN];
LL dp[MAXN];

int query(int node, int left, int right, int i, int j) {
    if (right < i || j < left) return 0;
    if (i <= left && right <= j) return tree[node];
    int mid = getmid;
    int a = query(leftnode, left, mid, i, j);
    int b = query(rightnode, mid+1, right, i, j);
    if (nums[a] > nums[b]) return a;
    return b;
}
void update(int node, int left, int right, int i) {
    if (right < i || i < left) return;
    if (left == right) {
        tree[node] = i;
        return;
    }
    int mid = getmid;
    if (i <= mid) update(leftnode, left, mid, i);
    else update(rightnode, mid+1, right, i);
    if (nums[tree[leftnode]] > nums[tree[rightnode]]) tree[node] = tree[leftnode];
    else tree[node] = tree[rightnode];
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = n-1; i >= 1; i--) {
        update(1, 1, n, i);
        dp[i] = nums[i] - i;
        int idx = query(1, 1, n, i+1, nums[i]);
        if (idx == 0) continue;
        LL tmp = dp[idx] - (nums[i] - idx);
        dp[i] += tmp + (n-nums[i]);
    }
    LL ret = 0;
    for (int i = 1; i <= n; i++) {
        ret += dp[i];
    }
    cout << ret << endl;


    return 0;
}