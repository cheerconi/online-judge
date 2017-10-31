#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 3e5 + 10;
int nums[MAXN], data[MAXN<<5], L[MAXN<<5], R[MAXN<<5], hsh[MAXN], tree[MAXN];
int tot, ret;

int build(int left, int right) {
    int cur = tot++;
    if (left < right) {
        int mid = (left+right) >> 1;
        L[cur] = build(left, mid);
        R[cur] = build(mid+1, right);
    }
    return cur;
}

int update(int left, int right, int pre, int val) {
    int cur = tot++;
    data[cur] = data[pre] + 1;
    if (left < right) {
        int mid = (left+right) >> 1;
        if (hsh[mid] >= val) {
            R[cur] = R[pre];
            L[cur] = update(left, mid, L[pre], val);
        }
        else {
            L[cur] = L[pre];
            R[cur] = update(mid+1, right, R[pre], val);
        }
    }
    return cur;
}

void query(int left, int right, int pre, int cur, int k) {
    if (ret != -1) return;
    if (left == right) {
        if (data[cur] >= k) {
            ret = left;
        }
        return;
    }
    int mid = (left+right) >> 1;
    if (data[L[cur]]-data[L[pre]] >= k) {
        query(left, mid, L[pre], L[cur], k);
    }
    if (data[R[cur]]-data[R[pre]] >= k) {
        query(mid+1, right, R[pre], R[cur], k);
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
    tree[0] = build(1, d);
    for (int i = 1; i <= n; i++) {
        tree[i] = update(1, d, tree[i-1], nums[i]);
    }
    int a, b, c;
    while (q--) {
        ret = -1;
        scanf("%d%d%d", &a, &b, &c);
        c = (b-a+1)/c + 1;
        query(1, d, tree[a-1], tree[b], c);
        printf("%d\n", ret==-1 ? ret : hsh[ret]);
    }
    return 0;
}