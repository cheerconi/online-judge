#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 250 + 5;
char graph[MAXN][MAXN];
int noise[MAXN][MAXN];
int vis[MAXN][MAXN];
int n, m, q, p;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool check(int i, int j, int id) {
    if (i >= n || i < 0) return false;
    if (j >= m || j < 0) return false;
    if (graph[i][j] == '*') return false;
    if (vis[i][j] == id) return false;
    return true;
}

void bfs(int i, int j, int id) {
    queue<pii> que;
    int now = (graph[i][j]-'A')*p + p;
    noise[i][j] += now;
    que.push({i, j});
    vis[i][j] = id;
    while (!que.empty()) {
        now /= 2;
        if (now == 0) break;
        int sz = que.size();
        for (int k = 0; k < sz; k++) {
            int a = que.front().first;
            int b = que.front().second;
            que.pop();
            for (int t = 0; t < 4; t++) {
                if (check(a+dx[t], b+dy[t], id)) {
                    vis[a+dx[t]][b+dy[t]] = id;
                    noise[a+dx[t]][b+dy[t]] += now;
                    que.push({a+dx[t], b+dy[t]});
                }
            }
        }
    }
}

int main() {
//    freopen("test.txt","r", stdin);
    scanf("%d%d%d%d", &n, &m, &p, &q);
    for (int i= 0; i < n; i++) {
        getchar();
        for (int j = 0; j < m; j++) {
            scanf("%c", &graph[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isalpha(graph[i][j]))  bfs(i, j, i*m+j+1);
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (noise[i][j] > q) cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}