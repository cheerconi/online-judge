#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
typedef long long LL;
const int MAXN = 1000 + 10;
int idx[2], nums[MAXN];
LL sum[2];
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        if (idx[i%2] == 0 || nums[idx[i%2]] < nums[i]) {
            idx[i%2] = i;
        }
        if (nums[i] > 0) {
            sum[i%2] += nums[i];
        }
    }
    if (nums[idx[0]] <= 0 && nums[idx[1]] <= 0) {
        if (nums[idx[0]] < nums[idx[1]]) {
            idx[0] = idx[1];
        }
        cout << nums[idx[0]] << '\n';
        cout << n-1 << '\n';
        for (int i = n; i > idx[0]; i--) {
            cout << i << '\n';
        }
        for (int i = 1; i < idx[0]; i++) {
            cout << "1\n";
        }
        return 0;
    }
    int p = 0;
    if (sum[1] > sum[0]) {
        p = 1;
    }
    vector<int> ret;
    list<LL> tmp;
    for (int i = 1; i <= n; i++) {
        if (i%2 != p || nums[i] <= 0) tmp.push_back(-1);
        else tmp.push_back(nums[i]);
    }
    while (tmp.size() > 1) {
        auto it = tmp.begin();
        int tot = 0;
        while (it != tmp.end()) {
            if (*it > 0) {
                tot++;
                it++;
                continue;
            }
            if (it == tmp.begin()) {
                ret.push_back(tot+1);
                it = tmp.erase(it);
                continue;
            }
            auto it1 = it; it1--;
            auto it2 = it; it2++;
            if (it2 == tmp.end()) {
                ret.push_back(tot+1);
                it = tmp.erase(it);
                continue;
            }
            if (*it1 > 0 && *it2 > 0 || *it1 < 0 && *it2 < 0) {
                *it1 += *it2;
                ret.push_back(tot+1);
                it = tmp.erase(it);
                it = tmp.erase(it);
                continue;
            }
            tot++;
            it++;
        }
    }
    cout << sum[p] << endl;
    cout << ret.size() << endl;
    for (int val : ret) {
        cout << val << endl;
    }
    return 0;
}