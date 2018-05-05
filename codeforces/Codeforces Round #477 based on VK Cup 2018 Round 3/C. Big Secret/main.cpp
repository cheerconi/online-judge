#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 70;
vector<LL> nums[MAXN], ret;

bool solve (int i) {
    if (nums[i].empty()) return true;
    if (ret.empty() && nums[i].size() > 1) return false;
    vector<LL> tmp;
    int j = 0;
    for (LL num : nums[i]) {
        if (tmp.empty()) tmp.push_back(num);
        else {
            bool flag = false;
            while (!flag && j < ret.size()) {
                if (ret[j] & (1LL<<i)) flag = true;
                tmp.push_back(ret[j++]);
            }
            if (flag) tmp.push_back(num);
            else return false;
        }
    }
    while (j < ret.size()) tmp.push_back(ret[j++]);
    swap(tmp, ret);
    return true;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    LL val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        for (int j = 60; j >= 0; j--) {
            if (val & (1LL<<j)) {
                nums[j].push_back(val);
                break;
            }
        }
    }
    bool flag = true;
    for (int i = 60; i >= 0; i--) {
        flag = solve(i);
        if (!flag) break;
    }
    if (flag) {
        cout << "Yes" << endl;
        for (int i = 0; i < ret.size(); i++) {
            cout << ret[i];
            if (i+1 == ret.size()) cout << endl;
            else cout << ' ';
        }
    }
    else cout << "No" << endl;
    return 0;
}