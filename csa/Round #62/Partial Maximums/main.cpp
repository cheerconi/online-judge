#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
const int MAXN = 2e5 + 10;
int n, tree[MAXN];
bool flag[MAXN];
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
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int ret = 0, ma = -1;
    for (int i = 0; i < n; i++) {
        if (nums[i] > ma) {
            ret++;
            ma = nums[i];
            flag[i] = true;
        }
    }
    vector<int> tmp = nums;
    sort(tmp.begin(), tmp.end());
    int m = unique(tmp.begin(), tmp.end()) - tmp.begin();
    int idx = 1;
    unordered_map<int, int> table;
    for (int i = 0; i < m; i++) {
        table[tmp[i]] = idx++;
    }
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        v[i] = ret;
        if (flag[i]) v[i]--;
    }
    vector<int> maxv(n, 0);
    for (int i = 0; i < n; i++) {
        maxv[i] = nums[i];
        if (i - 1 >= 0) maxv[i] = max(maxv[i], maxv[i-1]);
    }
    for (int i = 0; i < n; i++) {
        if (!flag[i]) {
            int val = find(table[maxv[n-1]]) - find(table[nums[i]]-1);
            if (val == 1) {
                int p = lower_bound(maxv.begin(), maxv.begin()+i, nums[i]) - maxv.begin();
                v[p]++;
            }
        }
        add(table[nums[i]]);
    }
    ret = 0;
    for (int item : v) ret = max(ret, item);
    cout << ret << endl;
    return 0;
}