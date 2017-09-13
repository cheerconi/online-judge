#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
int nums[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    vector<int> dp1, dp2;
    for (int i = 1; i < n; i++) {
        dp1.push_back(abs(nums[i]-nums[i-1]));
    }
    for (int i = 2; i < n; i++) {
        dp2.push_back(abs(nums[i]-nums[i-1]));
    }
    LL ret = 0;
    LL cur = 0;
    for (int i = 0; i < dp1.size(); i++) {
        if (i % 2 == 0) cur += dp1[i];
        else cur -= dp1[i];
        ret = max(ret, cur);
        if (cur < 0) cur = 0;
    }
    cur = 0;
    for (int i = 0; i < dp2.size(); i++) {
        if (i % 2 == 0) cur += dp2[i];
        else cur -= dp2[i];
        ret = max(ret, cur);
        if (cur < 0) cur = 0;
    }
    cout << ret << endl;


    return 0;
}