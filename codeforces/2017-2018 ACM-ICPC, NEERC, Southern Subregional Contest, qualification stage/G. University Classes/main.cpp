#include <iostream>
#include <algorithm>
using namespace std;
int dp[7];
int main() {
    int n;
    char bit;
    cin >> n;
    int ret = 0;
    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < 7; j++) {
            cin >> bit;
            dp[j] += bit - '0';
            ret = max(ret, dp[j]);
        }
    }
    cout << ret << endl;
    return 0;
}