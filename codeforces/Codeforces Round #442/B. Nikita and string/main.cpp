#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 5000 + 10;
int cnt[MAXN];
int dp[MAXN];

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        cnt[i+1] = cnt[i];
        if (s[i] == 'a') cnt[i+1]++;
    }
    for (int i = 1; i <= n; i++) {
        int tmp = min(cnt[i], i-cnt[i]);
        for (int j = 1; j < i; j++) {
            tmp = min(tmp, j-cnt[j]+cnt[i]-cnt[j]);
        }
        dp[i] = tmp;
    }
    int ret = min(cnt[n], n - cnt[n]);
    for (int i = 0; i <= n; i++) {
        ret = min(ret, n-i - (cnt[n]-cnt[i])+dp[i]);
    }
    cout << n - ret << endl;


    return 0;
}