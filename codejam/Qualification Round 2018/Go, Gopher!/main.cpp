#include <iostream>
#include <cmath>
#include <memory.h>
using namespace std;
const int MAXN = 20;
bool mat[MAXN][MAXN];
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, -1, 1, 1, -1};
bool ask(int x, int y) {
    cout << x << ' ' << y << endl;
    cin >> x >> y;
    if (x == 0 && y == 0) return true;
    mat[x][y] = true;
    return false;
}
bool solve(int n) {
    int x= 0, y = 0, cnt = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            int tmp = 0;
            for (int k = 0; k < 8; k++) {
                int u = i + dx[k];
                int v = j + dy[k];
                if (mat[u][v] == false) tmp++;
            }
            if (tmp > cnt) {
                cnt = tmp;
                x = i; y = j;
            }
            if (cnt == 8) break;
        }
    }
    if (ask(x, y)) {
        return true;
    }
    return false;
}
int main() {
    int cs, a;
    cin >> cs;
    for (int i = 1; i <= cs; i++) {
        cin >> a;
        int n = sqrt(a);
        memset(mat, 0, sizeof(mat));
        while (!solve(n)) ;
    }
    return 0;
}