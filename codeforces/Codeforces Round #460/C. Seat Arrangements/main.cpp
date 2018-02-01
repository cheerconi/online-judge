#include <iostream>
#include <string>
using namespace std;
const int MAXN = 2000 + 10;
string graph[MAXN];
int n, m, col[MAXN][MAXN], row[MAXN][MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = m-1; j >= 0; j--) {
            if (graph[i][j] == '.') {
                row[i][j] = row[i][j+1]+1;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = n-1; i >= 0; i--) {
            if (graph[i][j] == '.') {
                col[i][j] = col[i+1][j] + 1;
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (col[i][j] >= k) ret++;
            if (row[i][j] >= k) ret++;
        }
    }
    if (k == 1) ret = ret / 2;
    cout << ret << endl;


    return 0;
}