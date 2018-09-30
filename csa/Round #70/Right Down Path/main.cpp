#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 300 + 10;
int graph[MAXN][MAXN], a[MAXN][MAXN], b[MAXN][MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int pre = 0;
            if (j > 0) pre = a[i][j-1];
            if (graph[i][j] == 1) {
                a[i][j] = pre + 1;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = n-1; i >= 0; i--) {
            if (graph[i][j] == 1) {
                b[i][j] = b[i+1][j] + 1;
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] >= 2 && b[i][j] >= 2) {
                ret = max(ret, a[i][j] + b[i][j] - 1);
            }

        }
    }
    cout << ret << endl;

    return 0;
}