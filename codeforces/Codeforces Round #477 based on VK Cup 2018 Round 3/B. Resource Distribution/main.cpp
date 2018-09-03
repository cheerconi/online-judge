#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
struct Item{
    LL val, id;
    bool operator< (const Item & oth) const {
        return val < oth.val;
    }
};
const int MAXN = 300000 + 10;
Item nums[MAXN];
LL n;
bool check(LL s1, LL s2, int i) {
    LL cnt1 = s1 / nums[i].val;
    if (s1 % nums[i].val != 0) cnt1++;
    if (i+cnt1 >= n) return false;
    LL cnt2 = s2 / nums[i+cnt1].val;
    if (s2 % nums[i+cnt1].val != 0) cnt2++;
    if (i+cnt1+cnt2 <= n) return true;
    return false;
}
void solve (vector<LL> & ret1, vector<LL> & ret2, LL s1, LL s2, int i) {
    int j = i;
    LL tot = 0;
    while (j < n && tot < s1) {
        tot += nums[i].val;
        ret1.push_back(nums[j].id);
        j++;
    }
    tot = 0; i = j;
    while (j < n && tot < s2) {
        tot += nums[i].val;
        ret2.push_back(nums[j].id);
        j++;
    }
}



int main() {
    ios::sync_with_stdio(false);
    cout.tie(0); cout.tie(0);
    cin >> n;
    LL s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < n; i++) {
        cin >> nums[i].val;
        nums[i].id = i+1;
    }
    sort(nums, nums+n);
    vector<LL> ret1, ret2;
    for (int i = 0; i < n; i++) {
        if (check(s1, s2, i)) {
            solve(ret1, ret2, s1, s2, i);
            break;
        }
        if (check(s2, s1, i)) {
            solve(ret2, ret1, s2, s1, i);
            break;
        }
    }
    if (ret1.empty()) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
        cout << ret1.size() << ' ' << ret2.size() << endl;
        for (int i = 0; i < ret1.size(); i++) {
            cout << ret1[i];
            if (i+1 == ret1.size()) cout << endl;
            else cout << ' ';
        }
        for (int i = 0; i < ret2.size(); i++) {
            cout << ret2[i];
            if (i+1 == ret2.size()) cout << endl;
            else cout << ' ';
        }
    }


    return 0;
}