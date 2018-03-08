#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
const int MAXN = 5000 + 10;
int dist[MAXN], dp[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, sum = 0;
    cin >> n;
    for (int i = 2; i <= n+1; i++) {
        cin >> dist[i];
        sum += dist[i];
    }
    for (int i = 2; i <= n+1; i++) {
        dp[i] = dist[i] + dp[i-1];
    }
    int ret = INT_MAX, id = 0;
    for (int i = 1; i <= n; i++) {
        int cur = 0;
        for (int j = 1; j <= n; j++) {
            cur = max(cur, min(abs(dp[j]-dp[i]), sum - abs(dp[j]-dp[i])));
        }
        if (ret > cur) {
            ret = cur;
            id = i;
        }
    }
    cout << id << endl;


    return 0;
}