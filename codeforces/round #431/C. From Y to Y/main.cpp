#include <iostream>
#include <algorithm>
#include <string>
#include <limits.h>
using namespace std;
const int MAXN = 300;
int dp[MAXN];
int ret[26];

int main() {
//    freopen("test.txt", "r", stdin);
    for (int i = 2; i < MAXN; i++) {
        int tmp = INT_MAX;
        for (int j = 1; j < i; j++) {
            tmp = min(tmp, dp[j]+dp[i-j] + j * (i-j));
        }
        dp[i] = tmp;
    }
//    for (int i = 1; i < MAXN; i++) cout << dp[i] << ' ';
//    cout << endl;
    int k;
    scanf("%d", &k);
    if (k == 0) {
        cout << "a" << endl;
        return 0;
    }
    int j = MAXN-1;
    for (int i = 0; i < 26; i++) {
        if (k == 0) break;
        while (dp[j] > k) j--;
        k -= dp[j];
        ret[i] = j;
    }
    for (int i = 0; i < 26; i++) {
        cout << string(ret[i], 'a'+i);
    }
    cout << endl;
    return 0;
}