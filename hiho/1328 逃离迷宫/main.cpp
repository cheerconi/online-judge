#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
const int MAXN = 100 + 10;
char graph[MAXN][MAXN];
int a, b, c, d;
int n, m, k;
int dp[40][MAXN][MAXN];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct State {
    int s, x, y;
    State(int _s, int _x, int _y) {
        s = _s;
        x = _x;
        y = _y;
    }
};
bool haskey(int s, int i) {
    if (s&(1<<i)) return true;
    return false;
}

bool check(int s, int x, int y) {
    if (x < 0 || x >= n) return false;
    if (y < 0 || y >= m) return false;
    if (graph[x][y] == '#') return false;
    if (graph[x][y] >= 'a' && graph[x][y] <= 'z') {
        s |= (1<<(graph[x][y]-'a'));
    }
    if (dp[s][x][y] != -1) return false;
    if (graph[x][y] >= 'A' && graph[x][y] <= 'Z') {
        if (!haskey(s, graph[x][y]-'A')) return false;
    }

    return true;
}


int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d%d%d%d%d%d%d", &n, &m, &k, &a, &b, &c, &d);
    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < m; j++) {
            scanf("%c", &graph[i][j]);
        }
    }
    int x, y;
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &x, &y);
        graph[x][y] = 'a' + i;
    }
    memset(dp, -1, sizeof(dp));
    dp[0][a][b] = 0;
    if (a == c &&  b == d) {
        cout << 0 << endl;
        return 0;
    }
    queue<State> q;
    q.push(State(0, a, b));
    while (!q.empty()) {
        State tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int u = tmp.x + dx[i];
            int v = tmp.y + dy[i];

            if (check(tmp.s, u, v)) {
                if (u==c && v==d) {
                    cout << dp[tmp.s][tmp.x][tmp.y] + 1 << endl;
                    return 0;
                }
                if (graph[u][v] == '.' || (graph[u][v]>='A' && graph[u][v]<='Z')) {
                    q.push(State(tmp.s, u, v));
                    dp[tmp.s][u][v] = dp[tmp.s][tmp.x][tmp.y] + 1;
                }
                else if (graph[u][v]>='a' && graph[u][v]<='z') {
                    q.push(State(tmp.s|(1<<(graph[u][v]-'a')), u, v));
                    dp[tmp.s|(1<<(graph[u][v]-'a'))][u][v] = dp[tmp.s][tmp.x][tmp.y] + 1;
                }
            }
        }
    }
    cout << -1 << endl;




    return 0;
}