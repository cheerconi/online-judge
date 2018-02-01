#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAXN = 300000 + 10;
int id[MAXN], degree[MAXN], dp[MAXN][26];
int n, ret;
int vis[MAXN];

vector<int> edges[MAXN];

bool dfs (int cur) {
    vis[cur] = 1;
    int val = 0;
    for (int nxt : edges[cur]) {
        if (vis[nxt] == 1) {
            return false;
        }
        if (vis[nxt] == 0 && !dfs (nxt)) return false;
        for (int i = 0; i < 26; i++) {
            dp[cur][i] = max(dp[cur][i], dp[nxt][i]+(id[cur]==i));
            val = max(dp[cur][i], val);
        }
    }
    if (val == 0) {
        dp[cur][id[cur]]++;
        val = 1;
    }
    vis[cur] = -1;
    ret = max(ret, val);
    return true;
}

void solve () {
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            if (!dfs(i)) break;
        }
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (vis[i] != -1) {
            flag = false;
            break;
        }
    }
    if (flag) cout << ret << endl;
    else cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m, a, b;
    cin >> n >> m;
    string s; cin >> s;
    for (int i = 1; i <= n; i++) {
        id[i] = s[i-1] - 'a';
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (a == b) {
            cout << -1 << endl;
            return 0;
        }
        edges[a].push_back(b);
        degree[b]++;
    }
    solve ();
}