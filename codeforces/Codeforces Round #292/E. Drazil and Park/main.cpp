#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long LL;
typedef pair<LL, int> pli;
const int MAXN = 2e5 + 10;
const int MAXB = 20;
LL dist[MAXN], h[MAXN];
pli dp[2][MAXN][MAXB][2], ret[2][2];
void query(int idx, int a, int b, int i, pli tmp[]) {
    tmp[0] = max(dp[idx][a][i][0], dp[idx][b][i][0]);
    tmp[1] = min(dp[idx][a][i][0], dp[idx][b][i][0]);
    if (i == 0) return;
    if (tmp[0] == tmp[1]) tmp[1] = {LLONG_MIN, -1};
    tmp[1] = max(tmp[1], dp[idx][a][i][1]);
    tmp[1] = max(tmp[1], dp[idx][b][i][1]);
}
void make_table(int n) {
    for (int j = 1; j < MAXB; j++) {
        for (int i = 1; i < n && i+(1<<j)-1 <= n; i++) {
            int mid = i + (1<<(j-1));
            query(0, i, mid, j-1, dp[0][i][j]);
            query(1, i, mid, j-1, dp[1][i][j]);
        }
    }
}
LL solve(int a, int b) {
    int i = 0;
    while(a+(1<<i)-1 <= b) i++;
    i--;
    int mid = b - (1<<i) + 1;
    query(0, a, mid, i, ret[0]);
    query(1, a, mid, i, ret[1]);
    LL val = 0;
    if (ret[0][0].second != ret[1][0].second) val = ret[0][0].first + ret[1][0].first;
    else {
        val = ret[0][0].first + ret[1][1].first;
        val = max(val, ret[1][0].first + ret[0][1].first);
    }
    return val;


}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q, a, b, x, y;
    cin >> n >> q;
    for (int i = 2; i <= n+1; i++) {
        cin >> dist[i];
    }
    for (int i = n+2; i <= 2*n; i++) {
        dist[i] = dist[i-n];
    }
    for (int i = 3; i <= 2*n; i++) {
        dist[i] += dist[i-1];
    }
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        h[i+n] = h[i];
    }
    for (int i = 1; i <= 2*n; i++) {
        dp[0][i][0][0] = {dist[i] + 2*h[i], i};
        dp[1][i][0][0] = {2*h[i] - dist[i], i};
    }
    make_table(2*n);
    while (q--) {
        cin >> a >> b;
        if (a <= b) {
            x = b+1; y = a+n-1;
        }
        else {
            x = b+1; y = a-1;
        }
        cout << solve(x, y) << '\n';
    }
    return 0;
}