#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 55;
int nums[MAXN];
int pos, neg, n;
vector<pii> ret;
void solve() {
    if (nums[pos] <= 0 || nums[pos] < -nums[neg]) {
        ret.push_back({neg, n});
        for (int i = n-1; i >= 1; i--) {
            ret.push_back({neg, i});
            ret.push_back({i+1, i});
        }
    }
    else {
        ret.push_back({pos, 1});
        for (int i = 2; i <= n; i++) {
            ret.push_back({pos, i});
            ret.push_back({i-1, i});
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
        if (nums[i] >= nums[pos]) pos = i;
        if (nums[i] <= nums[neg]) neg = i;
    }
    solve();
    cout << ret.size() << endl;
    for (auto item : ret) {
        cout << item.first << ' ' << item.second << endl;
    }


    return 0;
}