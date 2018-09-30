#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
int nums[MAXN], hsh[MAXN];
int data[MAXN<<5], L[MAXN<<5], R[MAXN<<5], tree[MAXN];
int tot;
int build (int left, int right) {
    int cur = tot++;
    data[cur] = 0;
    if (left < right) {
        int mid = (left + right) >> 1;
        L[cur] = build(left, mid);
        R[cur] = build(mid+1, right);
    }
    return cur;
}
int update(int pre, int left, int right, int val) {
    int cur = tot++;
    data[cur] = data[pre]+1;
    if (left < right) {
        int mid = (left + right) >> 1;
        if (hsh[mid] >= val) {
            R[cur] = R[pre];
            L[cur] = update(L[pre], left, mid, val);
        }
        else {
            L[cur] = L[pre];
            R[cur] = update(R[pre], mid+1, right, val);
        }
    }
    return cur;
}
int query(int pre, int cur, int left, int right, int k) {
    if (left == right) return hsh[left];
    int mid = (left+right) >> 1;
    if (data[L[cur]]-data[L[pre]] >= k) {
        return query(L[pre], L[cur], left, mid, k);
    }
    else {
        return query(R[pre], R[cur], mid+1, right, k - data[L[cur]] + data[L[pre]]);
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
        hsh[i] = nums[i];
    }
    sort(hsh+1, hsh+n+1);
    int d = unique(hsh+1, hsh+n+1) - hsh - 1;
    tree[0] = build (1, d);
    for (int i = 1; i <= n; i++) {
        tree[i] = update(tree[i-1], 1, d, nums[i]);
    }
    int a, b, c;
    while (q--) {
        scanf("%d%d%d", &a, &b, &c);
        printf("%d\n", query(tree[a-1], tree[b], 1, d, c));
    }


    return 0;
}