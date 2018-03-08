#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long LL;
const int MAXN = 3e5 + 10;
vector<int> mat[MAXN];
int n, m;

LL row() {
    if (n == 2) return 0;
    LL a = mat[0][0] + mat[0][m-1];
    for (int j = 1; j < m-1; j++) {
        a += mat[0][j]*2;
    }
    LL b = mat[n-1][0] + mat[n-1][m-1];
    for (int j = 1; j < m-1; j++) {
        b += mat[n-1][j]*2;
    }
    a = max(a, b);
    b = LLONG_MIN;
    for (int i = 1; i < n-1; i++) {
        LL cur = -mat[i][0] - mat[i][m-1];
        for (int j = 1; j < m-1; j++) {
            cur -= mat[i][j] * 2;
        }
        b = max(b, cur);
    }
    return max(0LL, a+b);
}
LL col() {
    if (m == 2) return 0;
    LL a = mat[0][0] + mat[n-1][0];
    for (int i = 1; i < n-1; i++) {
        a += mat[i][0]*2;
    }
    LL b = mat[0][m-1] + mat[n-1][m-1];
    for (int i = 1; i < n-1; i++) {
        b += mat[i][m-1]*2;
    }
    a = max(a, b);
    b = LLONG_MIN;
    for (int j = 1; j < m-1; j++) {
        LL cur = -mat[0][j] - mat[n-1][j];
        for (int i = 1; i < n-1; i++) {
            cur -= mat[i][j] * 2;
        }
        b = max(b, cur);
    }
    return max(0LL, a+b);
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    LL sum = 0;
    for (int i = 0; i < n; i++) {
        mat[i] = vector<int>(m, 0);
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if ((i==0||i==n-1) && (j==0||j==m-1)) sum += mat[i][j];
            else if (i==0 || j==0 || i==n-1 ||j == m-1) sum += mat[i][j]*2;
            else sum += mat[i][j]*4;
        }
    }
    sum += max(col(), row());
    cout << sum << endl;


    return 0;
}