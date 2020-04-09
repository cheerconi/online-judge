#include <iostream>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef pair<int, int> pii;

constexpr int MAXN = 20000 + 10;
int nums[MAXN], rk[MAXN], height[MAXN], sa[MAXN];

void get_rank(int n) {
    rk[n] = 0;
    for (int i = 0; ; i++) {
        set<pii> table;
        for (int j = 0; j < n; j++) {
            int k = j + (1 << i);
            if (k > n) k = n;
            table.emplace(rk[j], rk[k]);
        }
        int idx = 1;
        map<pii, int> tmp;
        for (const auto& item : table) {
            tmp[item] = idx++;
        }
        for (int j = 0; j < n; j++) {
            int k = j + (1 << i);
            if (k > n) k = n;
            rk[j] = tmp[make_pair(rk[j], rk[k])];
        }
        if (idx == n + 1) break;
    }
    for (int i = 0; i <= n; i++) {
        sa[rk[i]] = i;
    }
}
void get_height(int n) {
    int pre = 0;
    for (int i = 0; i < n; i++) {
        pre = max(pre - 1, 0);
        int j = sa[rk[i]-1];
        while (i+pre < n && j+pre < n) {
            if (nums[i+pre] == nums[j+pre]) pre++;
            else break;
        }
        height[rk[i]] = pre;
    }
}

int main() {
//    freopen("../test.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << n << endl;
        return 0;
    }
    k--;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        rk[i] = nums[i];
    }
    get_rank(n);
    get_height(n);
    vector<pii> st;
    for (int i = 1; i <= k; i++) {
        while (!st.empty() && st.back().first >= height[i]) {
            st.pop_back();
        }
        st.emplace_back(height[i], i);
    }
    int idx = 0;
    int ret = st[idx].first;
    for (int i = k+1; i <= n; i++) {
        while (idx < st.size() && st[idx].second <= i-k) idx++;
        while (st.size() >= idx+1 && st.back().first >= height[i]) {
            st.pop_back();
        }
        st.emplace_back(height[i], i);
        ret = max(ret, st[idx].first);
    }
    cout << ret << endl;


    return 0;
}