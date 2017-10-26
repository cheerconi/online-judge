#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
const int MAXN = 2e5 + 10;
int bit[MAXN], nums[MAXN];
int n;

inline int lowbit (int i) {
    return i&(-i);
}
void update(int i, int val) {
    bit[i] = val;
    for (int j = i; j <= n; j += lowbit(j)) {
        bit[j] = max(bit[j], val);
    }
}
int query(int i) {
    int ret = 0;
    for (int j = i; j >= 1; j -= lowbit(j)) {
        ret = max(ret, bit[j]);
    }
    return ret;
}

int find(int val) {
    int start = 1, end = n;
    while (start < end) {
        int mid = (start + end) / 2;
        if (query(mid) > val) {
            end = mid;
        }
        else start = mid + 1;
    }
    if (query(start) > val) return start;
    else return 0;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
        update(i, nums[i]);
    }
    int start;
    while (start = find(0)) {
        printf("%d", nums[start]);
        update(start, 0);
        int cur = start;
        while (cur = find(nums[cur])) {
            printf(" %d", nums[cur]);
        }
        printf("\n");
    }



    return 0;
}