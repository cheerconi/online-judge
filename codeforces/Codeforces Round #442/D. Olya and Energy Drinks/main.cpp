#include <iostream>
#include <memory.h>
#include <set>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 1000 + 10;
char graph[MAXN][MAXN];
int dp[MAXN][MAXN];
int n, m, k;
set<int> col[MAXN], row[MAXN];
int a, b, c, d;


void solve () {
    dp[a][b] = 0;
    if (a == c && b == d) return;
    row[a].erase(b);
    col[b].erase(a);
    queue<pii> q;
    q.push({a, b});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        while (true) {
            auto it = row[x].upper_bound(y);
            if (it == row[x].end() || *it > y+k || graph[x][*it] == '#') break;
            dp[x][*it] = dp[x][y] + 1;
            q.push({x, *it});
            if (x == c && *it == d) return;
            col[*it].erase(x);
            row[x].erase(it);
        }
        while (true) {
            auto it = row[x].lower_bound(y);
            if (it == row[x].begin()) break;
            it--;
            if (*it+k < y || graph[x][*it] == '#') break;
            dp[x][*it] = dp[x][y] + 1;
            q.push({x, *it});
            if (x == c && *it == d) return;
            col[*it].erase(x);
            row[x].erase(it);
        }
        while (true) {
            auto it = col[y].upper_bound(x);
            if (it == col[y].end() || *it > x+k || graph[*it][y] == '#') break;
            dp[*it][y] = dp[x][y] + 1;
            q.push({*it, y});
            if (*it == c && y == d) return;
            row[*it].erase(y);
            col[y].erase(it);
        }
        while (true) {
            auto it = col[y].lower_bound(x);
            if (it == col[y].begin()) break;
            it--;
            if (*it+k < x || graph[*it][y] == '#') break;
            dp[*it][y] = dp[x][y] + 1;
            q.push({*it, y});
            if (*it == c && y == d) return;
            row[*it].erase(y);
            col[y].erase(it);
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
            row[i].insert(j);
            col[j].insert(i);
        }
    }
    memset(dp, -1, sizeof(dp));
    cin >> a >> b >> c >> d;
    solve();
    cout << dp[c][d] << endl;
    return 0;
}