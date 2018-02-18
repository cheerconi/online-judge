#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2000 + 50;
int nums[MAXN], dp[MAXN], dp2[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int tot = 0, cnt = 0;
    if (nums[0] != 1) tot++;
    for (int i = 0; i < n; i++) {
        if (i != 0 && nums[i] != nums[i-1]) {
            dp[tot++] = cnt;
            cnt = 1;
        }
        else cnt++;
    }
    if (cnt != 0) dp[tot++] = cnt;
    if (tot <= 4) {
        cout << n << endl;
        return 0;
    }
    for (int i = tot-1; i >= 0; i--) {
        dp2[i] = dp2[i+1];
        if (i % 2 == 1) {
            dp2[i] += dp[i];
        }
    }
    int ret = 0, cur = 0;
    for (int i = 0; i < tot; i++) {
        if (i % 2 == 0) {
            cur += dp[i];
        }
        else {
            int tmp = 0, tmp2 = 0;
            for (int j = i; j < tot; j += 2) {
                tmp2 += dp[j];
                tmp = max(tmp2+dp[j+1], tmp+dp[j+1]);
                ret = max(cur+tmp+dp2[j+2], ret);
            }
        }
    }
    cout << ret << endl;
    return 0;
}