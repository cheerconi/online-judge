#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAXN = 55;
int mat[MAXN][MAXN];
bool items[2][MAXN];
int n, m;
vector<int> cur[2];

void dfs(int i, int idx) {
    if (items[idx][i]) return;
    cur[idx].push_back(i);
    items[idx][i] = true;
    if (idx == 0) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) dfs (j, 1-idx);
        }
        return;
    }
    for (int j = 0; j < n; j++) {
        if (mat[j][i] == 1) dfs (j, 1-idx);
    }
}
bool check () {
    for (int i : cur[0]) {
        for (int j : cur[1]) {
            if (mat[i][j] == 0) return false;
        }
    }
    return true;
}

int main () {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '#') {
                mat[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (items[0][i]) continue;
        dfs (i, 0);
        if (!check()) {
            cout << "No" << endl;
            return 0;
        }
        cur[0].clear();
        cur[1].clear();
    }
    for (int j = 0; j < m; j++) {
        if (items[1][j]) continue;
        if (!check()) {
            cout << "No" << endl;
            return 0;
        }
        cur[0].clear();
        cur[1].clear();
    }
    cout << "Yes" << endl;
}
