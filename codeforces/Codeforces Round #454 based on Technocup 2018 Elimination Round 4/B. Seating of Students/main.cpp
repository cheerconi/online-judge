#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > ret;
bool solve (int n, int m) {
    if (n == 1) {
        if (m == 1) {
            ret[0][0] = 1;
            return true;
        }
        if (m <= 3) return false;
        int idx = 0;
        for (int i = 2; i <= m; i += 2) {
            ret[0][idx++] = i;
        }
        for (int i = 1; i <= m; i += 2) {
            ret[0][idx++] = i;
        }
        return true;
    }
    int a, b;
    if (n == 2) {
        if (m <= 3) return false;
        if (m % 2 == 0) {
            a = 1;
            b = 2;
        }
        else {
            a = 1;
            b = 1;
        }
        int idx = 0;
        for (int i = 0; i < m; i++) {
            ret[0][idx++] = (a-1)*m + b;
            a = (a+1) % n;
            if (a == 0) a += n;
            b = (b+1) % m;
            if (b == 0) b += m;
        }
        if (m % 2 == 0) {
            a = 2;
            b = 4;
        }
        else {
            a = 2;
            b = (m+1) / 2;
        }
        idx = 0;
        for (int i = 0; i < m; i++) {
            ret[1][idx++] = (a-1)*m + b;
            a = (a+1) % n;
            if (a == 0) a += n;
            b = (b+1) % m;
            if (b == 0) b += m;
        }
        return true;
    }
    if (n == 3) {
        if (m <= 2) return false;
        if (m == 3) {
            ret[0][0] = 5;
            ret[0][1] = 3;
            ret[0][2] = 1;
            ret[1][0] = 9;
            ret[1][1] = 4;
            ret[1][2] = 8;
            ret[2][0] = 7;
            ret[2][1] = 2;
            ret[2][2] = 6;
            return true;
        }
        solve(2, m);
        int idx = 0;
        for (int i = 2; i <= m; i += 2) ret[2][idx++] = i;
        for (int i = 1; i <= m; i += 2) ret[2][idx++] = i;
        return true;
    }
    int x = 0;
    for (int i = 2; i <= n; i += 2) {
        int y = 0;
        for (int j = 2; j <= m; j += 2) {
            ret[x][y++] = (i-1)*m + j;
        }
        for (int j = 1; j <= m; j += 2) {
            ret[x][y++] = (i-1)*m + j;
        }
        x++;
    }
    for (int i = 1; i <= n; i += 2) {
        int y = 0;
        for (int j = 2; j <= m; j += 2) {
            ret[x][y++] = (i-1)*m + j;
        }
        for (int j = 1; j <= m; j += 2) {
            ret[x][y++] = (i-1)*m + j;
        }
        x++;
    }
    return true;

}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int a, b;
    cin >> a >> b;
    int n = a, m = b;
    if (n > m) swap(m, n);
    ret = vector<vector<int> >(n, vector<int>(m, 0));
    if (solve(n, m)) {
        cout << "YES" << endl;
        if (n == a) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << ret[i][j];
                    if (j != m-1) cout << ' ';
                }
               cout << endl;
            }
        }
        else {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int x = ret[j][i] / m;
                    if (ret[j][i] % m != 0) x++;
                    int y = ret[j][i] % m;
                    if (y == 0) y += m;
                    cout << (y-1)*n + x;
                    if (j != n-1) cout << ' ';
                }
                cout << endl;
            }

        }

    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
