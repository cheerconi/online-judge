#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
const int MAXN = 5000 + 10;
int nums[MAXN], dp[MAXN];
int n;
int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n;
    char c;
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c", &c);
        if (c == 'F') nums[i] = 0;
        else nums[i] = 1;
    }
    int ret = n, k = 1;
    for (int j = 1; j <= n; j++) {
        memset(dp, 0, sizeof(dp));
        int cur = 0;
        for (int i = 0; i+j <= n; i++) {
            if (i > 0) {
                dp[i] += dp[i-1] + nums[i] - nums[i-1];
            }
            else dp[i] = nums[i];
            if (dp[i] & 1) {
                dp[i]++;
                dp[i+j]--;
                cur++;
            }
        }
        for (int i = n-j+1; i < n; i++) {
            dp[i] += dp[i-1] + nums[i] - nums[i-1];
            if (dp[i] & 1) {
                cur = -1;
                break;
            }
        }
        if (cur >= 0 && cur < ret) {
            ret = cur;
            k = j;
        }
    }
    cout << k << ' ' << ret << endl;
    return 0;
}