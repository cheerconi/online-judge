#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
int nums[MAXN];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        scanf("%d%d", &n, &s);
        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }
        int i = 0, j = 0;
        int sum = 0, ret = INT_MAX;
        while (j < n) {
            if (sum >= s) {
                ret = min(ret, j-i);
                sum -= nums[i++];
            }
            else {
                sum += nums[j++];
            }
        }
        while (sum >= s && i < n) {
            ret = min(ret, j - i);
            sum -= nums[i++];
        }
        if (ret == INT_MAX) ret = 0;
        printf("%d\n", ret);

    }

    return 0;
}