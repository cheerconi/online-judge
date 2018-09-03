#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 5000 + 10;
int nums[MAXN];
LL pre[MAXN], suf[MAXN], dp[MAXN];
int ind[MAXN];
int main () {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        pre[i] = nums[i];
        if (i > 0) pre[i] += pre[i-1];
    }
    for (int i = n-1; i >= 0; i--) {
        suf[i] = suf[i+1] + nums[i];
    }
    for (int i = 0; i <= n; i++) {
        dp[i] = suf[i];
        ind[i] = n;
        for (int j = i; j < n; j++) {
            LL tmp = suf[i] - 2*suf[j];
            if (dp[i] < tmp) {
                dp[i] = tmp;
                ind[i] = j;
            }
        }
    }
    int out[] = {0, 0, ind[0]};
    LL ret = dp[0];
    for (int j = 0; j < n; j++) {
        LL tmp = dp[j+1] - pre[j];
        if (tmp > ret) {
            ret = tmp;
            out[1] = j+1;
            out[2] = ind[j+1];
        }
    }
    for (int i = 0; i <n; i++) {
        for (int j = i; j < n; j++) {
            LL tmp = 2*pre[i] - pre[j] + dp[j+1];
            if (tmp > ret) {
                ret = tmp;
                out[0] = i+1;
                out[1] = j+1;
                out[2] = ind[j+1];
            }
        }
    }
    cout << out[0] << ' ' << out[1] << ' ' << out[2] << endl;
    return 0;
}