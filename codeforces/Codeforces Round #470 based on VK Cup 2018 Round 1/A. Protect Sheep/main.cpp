#include <iostream>
#include <string>
using namespace std;
const int MAXN = 500 + 10;
string mat[MAXN];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    bool flag = true;
    for (int i = 0; i < n && flag; i++) {
        for (int j = 0; j < m && flag; j++) {
            if (mat[i][j] != 'W') continue;
            for (int k = 0; k < 4; k++) {
                int x = dx[k] + i;
                int y = dy[k] + j;
                if (x >= n || x < 0 || y >= m || y < 0) continue;
                if (mat[x][y] == 'S') {
                    flag = false;
                    break;
                }
            }
        }
    }
    if (!flag) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '.') cout << 'D';
            else cout << mat[i][j];
        }
        cout << '\n';
    }
    return 0;
}