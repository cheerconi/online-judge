#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
typedef long long LL;
const int MAXN = 5000 + 10;
const int MAXV = 1e4 + 10;
int ret[MAXN], cnt[MAXN];
LL nums[MAXN];
bool state[MAXV];
vector<LL> ps;
void make_table() {
    for (LL i = 2; i < MAXV; i++) {
        if (state[i]) continue;
        for (LL j = i*i; j < MAXV; j += i) {
            state[j] = true;
        }
    }
    for (int i = 2; i < MAXV; i++) {
        if (!state[i]) ps.push_back(i);
    }


}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    make_table();
    int n; cin >> n;
    vector<LL> v;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        for (LL j : ps) {
            if (j*j > abs(nums[i])) break;
            LL tmp = j * j;
            while (nums[i] % tmp == 0) {
                nums[i] = nums[i] / tmp;
            }
        }
        v.push_back(nums[i]);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for (int i = 0; i < n; i++) {
        int p = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
        nums[i] = p;
    }
    int zero_idx = lower_bound(v.begin(), v.end(), 0) - v.begin();
    if (v[zero_idx] != 0) zero_idx = -1;
    for (int i = 0; i < n; i++) {
        memset(cnt, 0, sizeof(cnt));
        bool zero = false;
        int cur = 0;
        for (int j = i; j < n; j++) {
            if (nums[j] == zero_idx) zero = true;
            if (cnt[nums[j]] != 1) {
                cnt[nums[j]]++;
                cur++;
            }
            int idx = cur;
            if (idx != 1 && zero) idx--;
            ret[idx]++;
        }

    }
    for (int i = 1; i <= n; i++) {
        cout << ret[i];
        if (i == n) cout << endl;
        else cout << ' ';

    }

}