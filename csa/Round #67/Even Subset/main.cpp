#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
int nums[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums+n, greater<int>());
    LL ret = 0;
    for (int i = 0; i+1 < n; i += 2) {
        if (nums[i]+nums[i+1] > 0) {
            ret += nums[i] + nums[i+1];
        }
    }
    cout << ret << endl;



    return 0;
}