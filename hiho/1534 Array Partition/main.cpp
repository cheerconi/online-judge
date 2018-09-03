#include <iostream>
#include <vector>
#include <algorithm>
typedef long long LL;
using namespace std;
const int MAXN = 100000 + 10;
LL pre[MAXN];
LL rear[MAXN];
LL nums[MAXN];
int n;

vector<int> find(LL v[], LL val) {
    vector<int> ret;
    for (int i = 1; i <= n; i++) {
        if (v[i] == val) ret.push_back(i);
    }
    return ret;
}

LL count(vector<int> const & v1, vector<int> const & v2) {
    LL ret = 0;
    for (int pos : v1) {
        auto it = upper_bound(v2.begin(), v2.end(), pos+1);
        ret += v2.end() - it;
    }
    return ret;
}


int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &nums[i]);
        pre[i] = pre[i-1] + nums[i];
    }
    for (int i = n; i >= 1; i--) rear[i] = rear[i+1] + nums[i];
    LL avg = pre[n] / 3;
    if (pre[n] % 3 == 0) {
        LL ret = 0;
        vector<int> pre0 = find(pre, avg);
        vector<int> rear0 = find(rear, avg);
        ret += count(pre0, rear0);
        cout << ret << endl;
    }
    else if (abs(pre[n] % 3) == 1) {
        LL delta = pre[n] % 3;
        vector<int> pre0 = find(pre, avg);
        vector<int> rear0 = find(rear, avg);
        vector<int> pre1 = find(pre, avg+delta);
        vector<int> rear1 = find(rear, avg+delta);
        LL ret = 0;
        ret += count(pre0, rear0);
        ret += count(pre0, rear1);
        ret += count(pre1, rear0);
        cout << ret << endl;
     }
    else {
        LL delta = pre[n] % 3 / 2;
        vector<int> pre0 = find(pre, avg);
        vector<int> rear0 = find(rear, avg);
        vector<int> pre1 = find(pre, avg+delta);
        vector<int> rear1 = find(rear, avg+delta);
        LL ret = 0;
        ret += count(pre1, rear1);
        ret += count(pre0, rear1);
        ret += count(pre1, rear0);
        cout << ret << endl;
    }

    return 0;
}