#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
int tree[MAXN], nums[MAXN], n, dp[MAXN], ret[MAXN];
inline int lowbit(int i) {
    return i&(-i);
}
void add (int i) {
    while (i <= n) {
        tree[i]++;
        i += lowbit(i);
    }
}
int find (int i) {
    int ret = 0;
    while (i > 0) {
        ret += tree[i];
        i -= lowbit(i);
    }
    return ret;
}
int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
        dp[i] = max(nums[i], dp[i-1]);
    }
    for (int i = n; i >= 1; i--) {
        add (nums[i]);
        if (nums[i] == dp[i]) ret[nums[i]]--;
        else {
            int cnt = find(n) - find(nums[i]);
            if (cnt == n-nums[i]-1) ret[dp[i]]++;
        }
    }
    int val = ret[1];
    int pos = 1;
    for (int i = 2; i <= n; i++) {
        if (val < ret[i]) {
            val = ret[i];
            pos = i;
        }
    }
    cout << pos << endl;
};