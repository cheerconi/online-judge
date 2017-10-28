#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;
int nums[MAXN];
bool vis[MAXN];
vector<vector<int> > group;
int n;
LL solve () {
    if (group.size() <= 2) return 1LL * n * n;
    vector<int> dp;
    for (vector<int> & item : group) {
        dp.push_back(item.size());
    }
    sort(dp.begin(), dp.end(), greater<int>());
    LL ret = 1LL * (dp[0] + dp[1]) * (n - dp[0] - dp[1]);
    for (int i = 2; i < dp.size(); i++) {
        ret += 1LL * dp[i] * (n - dp[i]);
    }
    return 1LL * n * n - ret;






}
int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        group.push_back(vector<int>(1, i));
        vis[i] = true;
        int j = i;
        while (nums[j] != group.back()[0]) {
            group.back().push_back(nums[j]);
            j = nums[j];
            vis[j] = true;
        }
    }
    cout << solve() << endl;


    return 0;
}