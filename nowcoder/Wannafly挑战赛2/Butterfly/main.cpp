#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2e3 + 10;
int dp[5][MAXN][MAXN];
char graph[MAXN][MAXN];
int n, m;
int key;
void build (int k, int dx, int dy, int sx, int ex, int sy, int ey) {
    int deltax = 1;
    if (sx > ex) deltax = -1;
    int deltay = 1;
    if (sy > ey) deltay = -1;
    for (int i = sx; i != ex; i += deltax) {
        for (int j = sy; j != ey; j += deltay) {
            dp[k][i][j] = dp[k][i+dx][j+dy];
            if (graph[i][j] == 'X') dp[k][i][j]++;
            else dp[k][i][j] = 0;
            if (k == 0) key = max(key, dp[k][i][j]);
        }
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        getchar();
        for (int j = 1; j <= m; j++) {
            scanf("%c", &graph[i][j]);
        }
    }
    build (0, -1, 0, 1, n+1, 1, m+1);
    build (1, -1, -1, 1, n+1, 1, m+1);
    build (2, 1, -1, n, 0, 1, m+1);
    build (3, -1, 1, 1, n+1, m, 0);
    build (4, 1, 1, n, 0, m, 0);
    if (key % 2 != 0) key++;
    key = key / 2;
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (graph[i][j] == 'O') continue;
            int tmp = min(dp[1][i][j], dp[2][i][j]);
            tmp = min(tmp, dp[3][i][j]);
            tmp = min(tmp, dp[4][i][j]);
            tmp = min(tmp, key);
            while (ret < tmp*2-1) {
                int x = i + tmp -1;
                int y = j + tmp -1;
                if (dp[0][x][y] < tmp*2-1) {
                    tmp--;
                    continue;
                }
                y = j - (tmp - 1);
                if (dp[0][x][y] < tmp*2-1) {
                    tmp--;
                    continue;
                }
                ret = tmp*2 -1;
            }
        }
    }
    cout << ret << endl;



    return 0;
}