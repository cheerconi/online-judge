#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
const int MAXN = 1e5 + 10;
int nums[MAXN], sec[MAXN];
int dp[20];
int main() {
//    freopen("test.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        int m = 1 << n;
        for (int i = 0; i < m; i++) {
            scanf("%d", &nums[i]);
        }
        for (int i = 0; i < 20; i++) {
            dp[i] = INT_MAX;
        }
        for (int i = 0; i < m; i++) sec[i] = 0;
        int idx = 0;
        while (m > 1) {
            for (int i = 0; i < m; i += 2) {
                vector<int> tmp{nums[i], nums[i+1], sec[i], sec[i+1]};
                sort(tmp.begin(), tmp.end());
                sec[i/2] = tmp[2];
                dp[idx] = min(dp[idx], sec[i/2]);
                nums[i/2] = max(nums[i], nums[i+1]);

            }
            m /= 2;
            idx++;
        }
        idx = 0;
        int i = 1;
        while  (i <= (1<<n)) {
            while (i <= (1<<n) && i <= dp[idx]) {
                printf("%d", idx);
                if (i == (1<<n)) printf("\n");
                else printf(" ");
                i++;
            }
            idx++;
        }
    }
    return 0;
}