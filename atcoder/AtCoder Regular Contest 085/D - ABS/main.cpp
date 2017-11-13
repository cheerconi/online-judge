#include <iostream>
#include <map>
#include <algorithm>
#include <limits.h>
using namespace std;
int n;
const int MAXN = 2000 + 10;
map<int,int> dp[2][MAXN];
int nums[MAXN];

int get(int val, int i, int j) {
    if (dp[i][j].find(val) != dp[i][j].end()) return dp[i][j][val];
    if (j == n-1) {
        dp[i][j][val] = abs(val - nums[j]);
        return dp[i][j][val];
    }
    int ret;
    if (i == 0) {
        ret = abs(val - nums[n-1]);
        for (int k = j; k+1 < n; k++) {
            ret = max(ret, get(nums[k], 1-i, k+1));
        }
        dp[i][j][val] = ret;
    }
    else {
        ret = abs(val - nums[n-1]);
        for (int k = j; k+1 < n; k++) {
            ret = min(ret, get(nums[k], 1-i, k+1));
        }
    }
    dp[i][j][val] = ret;
    return ret;
}


int main() {
    int z, w;
    cin >> n >> z >> w;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << get(w, 0, 0);

    return 0;
}