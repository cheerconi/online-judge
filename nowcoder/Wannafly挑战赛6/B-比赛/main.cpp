#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long double LD;
LD a[12], b[12], c[12], nums[12];
int main() {
//    freopen("test.txt", "r", stdin);
    for (int i = 0; i < 12; i++) cin >> a[i];
    for (int i = 0; i < 12; i++) cin >> b[i];
    for (int i = 0; i < 12; i++) cin >> c[i];
    for (int i = 0; i < 12; i++) {
        nums[i] = 1 - (1 - a[i]) * (1 - b[i]) * (1 - c[i]);
    }
    vector<LD> dp(13, 0);
    dp[0] = 1;
    for (int i = 0; i < 12; i++) {
        vector<LD> tmp(13, 0);
        for (int j = 0; j < 12; j++) {
            tmp[j] += dp[j] * (1 - nums[i]);
            tmp[j+1] += dp[j] * nums[i];
        }
        swap(tmp, dp);
    }
    for (int i = 0; i <= 12; i++) {
        printf("%.6Lf\n", dp[i]);
    }

    return 0;
}