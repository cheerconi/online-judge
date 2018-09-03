#include <iostream>
#include <algorithm>
#include <vector>
#define leftnode (node<<1)
#define rightnode ((node<<1)|1)
#define getmid ((left+right)>>1)
using namespace std;
const int MAXN = 4e4 + 10;
int nums[MAXN];
vector<int> items[MAXN<<2];


void build (int node, int left, int right) {
    if (left == right) {
        items[node].push_back(nums[left]);
        return;
    }
    int mid = getmid;
    build (leftnode, left, mid);
    build (rightnode, mid+1, right);
    items[node].resize(items[leftnode].size() + items[rightnode].size());
    merge(items[leftnode].begin(), items[leftnode].end(), items[rightnode].begin(),
          items[rightnode].end(), items[node].begin());
}

int query(int node, int left, int right, int i, int j, int mod) {
    if (j < left || right < i) return -1;
    if (i <= left && right <= j) {
        int ret = -1, val = mod;
        auto it = lower_bound(items[node].begin(), items[node].end(), val);
        while (it != items[node].end()) {
            val += mod;
            if (it == items[node].begin()) {
                it = lower_bound(items[node].begin(), items[node].end(), val);
                continue;
            }
            auto pre = it; pre--;
            ret = max(ret, *pre % mod);
            if (ret == mod-1) break;
            it = lower_bound(items[node].begin(), items[node].end(), val);
        }
        it--;
        ret = max(ret, *it % mod);
        return ret;
    }
    int mid = getmid;
    int ret = -1;
    ret = max(ret, query(leftnode, left, mid, i, j, mod));
    if (ret == mod-1) return ret;
    ret = max(ret, query(rightnode, mid+1, right, i, j, mod));
    return ret;
}


int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q, mod, a, b;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    build (1, 1, n);

    while (q--) {
        cin >> a >> b >> mod;
        cout << query(1, 1, n, a, b, mod) << '\n';
    }



    return 0;
}