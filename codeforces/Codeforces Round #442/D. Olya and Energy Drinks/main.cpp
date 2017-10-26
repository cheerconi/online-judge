#include <iostream>
#include <limits.h>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
const int MAXN = 1000 + 10;
int dp[MAXN][MAXN];
int n, m, k;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
char graph[MAXN][MAXN];

bool check (int a, int b) {
    if (a <= 0 || a > n) return false;
    if (b <= 0 || b > m) return false;
    if (graph[a][b] == '#') return false;
    return true;
}

void solve(int a, int b, int c, int d) {
    dp[a][b] = 0;
    queue<pip> q;
    q.push({0, {a,b}});
    while (!q.empty()) {
        int val = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        if (dp[x][y] < val) continue;
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= k; j++) {
                if (!check(x+dx[i]*j, y+dy[i]*j)) break;
                if (dp[x+dx[i]*j][y+dy[i]*j] > val+1) {
                    dp[x+dx[i]*j][y+dy[i]*j] = val+1;
                    q.push({val+1, {x+dx[i]*j, y+dy[i]*j}});
                }
            }
        }
    }

}
int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        getchar();
        for (int j = 1; j <= m; j++) {
            scanf("%c", &graph[i][j]);
            dp[i][j] = INT_MAX;
        }
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    solve(a, b, c, d);
    if (dp[c][d] == INT_MAX) cout << -1 << endl;
    else cout << dp[c][d] << endl;



    return 0;
}