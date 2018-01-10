#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
int nums[MAXN], n;
LL tree[MAXN];
int lowbit(int i) {
    return i&(-i);
}
void add (int i, LL val) {
    while (i <= n) {
        tree[i] += val;
        i += lowbit(i);
    }
}
LL find (int i) {
    LL ret = 0;
    while (i > 0) {
        ret += tree[i];
        i -= lowbit(i);
    }
    return ret;
}

unordered_map<int, LL> table;
LL solve (int k) {
    auto it = table.find(k);
    if (it != table.end()) return it->second;
    LL ret = 0;
    LL len = k, coeff = 1;
    for (LL i = 2; i <= n; i += len, len *= k) {
        ret += coeff * (find(min((LL)n, i+len-1)) - find(i-1));
        coeff++;
    }
    table[k] = ret;
    return ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    sort(nums+1, nums+n+1, greater<int>());
    for (int i = 1; i <= n; i++) {
        add(i, nums[i]);
    }
    LL cur = 0, cost = 0;
    for (int i = n; i > 1; i--) {
        cur += nums[i];
        cost += cur;
    }
    table[1] = cost;
    int q, k;
    cin >> q;
    while (q--) {
        cin >> k;
        cout << solve (k);
        if (q == 0) cout << endl;
        else cout << ' ';
    }
    return 0;
}