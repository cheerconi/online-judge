#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, char> pic;
int dp[101][101][26];
vector<pic> edges[101];
int n;

int solve (int i, int j, char c) {
    if (dp[i][j][c-'a'] != 0) return dp[i][j][c-'a'];
    bool ret = false;
    for (pic item : edges[i]) {
        if (item.second < c) continue;
        if (solve(j, item.first, item.second) == -1) {
            ret = true;
            break;
        }
    }
    if (ret) dp[i][j][c-'a'] = 1;
    else dp[i][j][c-'a'] = -1;
    return dp[i][j][c-'a'];
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m;
    cin >> n >> m;
    int a, b;
    char c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (solve(i, j, 'a') == 1) cout << 'A';
            else cout << 'B';
        }
        cout << '\n';
    }
    return 0;
}