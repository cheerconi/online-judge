#include <iostream>
using namespace std;
const int MAXN = 600 + 10;
int mat[MAXN][MAXN], ret[MAXN][MAXN];
int n, m, x, y;
void solve (int i, int j) {
    bool one = false, two = false;
    if (i < n && j < m) one = true;
    if (i-x >= 0 && i-x < n && j-y >= 0 && j-y < m) two = true;
    if (!one && !two) return;
    if(one && !two) {
        ret[i][j] = mat[i][j];
        return;
    }
    if (!one && two) {
        ret[i-x][j-y] = mat[i][j];
        return;
    }
    ret[i][j] = mat[i][j] - ret[i-x][j-y];

}
int main() {
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n+x; i++) {
        for (int j = 0; j < m+y; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < n+x; i++) {
        for (int j = 0; j < m+y; j++) {
            solve (i, j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ret[i][j];
            if (j+1 != m) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}