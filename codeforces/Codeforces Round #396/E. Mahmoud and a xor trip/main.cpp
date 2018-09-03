#include <vector>
#include <iostream>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
vector<int> edges[MAXN];
int dp[MAXN][2], nums[MAXN];
LL ret;
void dfs(int i, int cur, int par) {
    int b = 0;
    if (nums[cur] & (1<<i)) {
        b = 1;
    }
    dp[cur][0] = dp[cur][1] = 0;
    int cnt[2] = {0};
    for (int nxt : edges[cur]) {
        if (nxt == par) continue;
        dfs(i, nxt, cur);
        dp[cur][0] += dp[nxt][b];
        dp[cur][1] += dp[nxt][1-b];
        cnt[0] += dp[nxt][0];
        cnt[1] += dp[nxt][1];
    }
    LL tot = 0;
    for (int nxt : edges[cur]) {
        if (nxt == par) continue;
        cnt[0] -= dp[nxt][0];
        cnt[1] -= dp[nxt][1];
        tot += 1LL * dp[nxt][0] * cnt[1-b];
        tot += 1LL * dp[nxt][1] * cnt[b];
    }
    tot += b + dp[cur][1];
    dp[cur][b]++;
    ret += tot * (1<<i);
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, a, b;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 0; i < 20; i++) {
        dfs(i, 1, 0);
    }
    cout << ret << endl;



}