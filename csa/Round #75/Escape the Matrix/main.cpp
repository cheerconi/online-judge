#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 500 + 10;
int n, m;
string mat[MAXN];
int ret[MAXN][MAXN];
void solve(int i, int j) {
    vector<pii> v;
    v.push_back({i, j});
    ret[i][j] = 10;
    int tag = 0;
    while (true) {
        int x = v.back().first, y = v.back().second;
        if (mat[x][y] == 'U') x--;
        else if (mat[x][y] == 'R') y++;
        else if (mat[x][y] == 'D') x++;
        else y--;
        if (x < 0 || y < 0 || x == n || y == m) {
            tag = 1;
            break;
        }
        if (ret[x][y] == 10 || ret[x][y] == -1) {
            tag = -1;
            break;
        }
        if (ret[x][y] == 1) {
            tag = 1;
            break;
        }
        ret[x][y] = 10;
        v.push_back({x, y});
    }
    for (pii item : v) {
        ret[item.first][item.second] = tag;
    }
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ret[i][j] == 0) solve(i, j);
            if (ret[i][j] == 1) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}