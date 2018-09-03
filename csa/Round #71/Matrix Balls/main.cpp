#include <iostream>
#include <climits>
using namespace std;
const int MAXN = 500 + 10;
int graph[MAXN][MAXN], par[MAXN*MAXN], ret[MAXN][MAXN];
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {-1, 1, 0, -1, 1, -1, 0, 1};

int find (int i) {
    if (par[i] == i) return i;
    return par[i]=find(par[i]);
}
void add (int i, int j) {
    int a = find(i);
    int b = find(j);
    if (a == b) return;
    int a1 = a / 501;
    int a2 = a % 501;
    int b1 = b / 501;
    int b2 = b % 502;
    if (graph[i/501][i%501] > graph[j/501][j%501]) par[a] = b;
    else par[b] = a;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            par[i*501+j] = i*501+j;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int id = -1, val = graph[i][j];
            for (int k = 0; k < 8; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x < 0 || x >= n || y < 0 || y >= m) continue;
                if (graph[x][y] < val) {
                    val = graph[x][y];
                    id = x*501 + y;
                }
            }
            if (id != -1) {
                add (i*501+j, id);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp = find(i*501+j);
            int x = tmp / 501;
            int y = tmp % 501;
            ret[x][y]++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ret[i][j];
            if (j+1 != m) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}