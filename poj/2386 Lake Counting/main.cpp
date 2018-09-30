#include <iostream>
#include <string>
using namespace std;

const int MAXN = 110;
string graph[MAXN];
int n, m;

int offset[] = {0, -1, 1};

void solve(int i, int j) {
    if (i < 0 || i >= n) return;
    if (j < 0 || j >= m) return;
    if (graph[i][j] == '.') return;
    graph[i][j] = '.';
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            solve(i+offset[a], j+offset[b]);
        }
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) cin >> graph[i];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 'W') {
                cnt++;
                solve(i, j);
            }
        }
    }
    cout << cnt << endl;
}