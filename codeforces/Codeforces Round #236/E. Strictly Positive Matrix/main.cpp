#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
const int MAXN = 2000 + 10;
bool vis[MAXN], state[MAXN][MAXN];
int n;
void dfs (int cur, bool reverse = false) {
    vis[cur] = true;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        if (!reverse && state[cur][i]) {
            dfs(i, reverse);
        }
        else if (reverse && state[i][cur]) {
            dfs(i, reverse);
        }
    }
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int val, s = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> val;
            if (val) state[i][j] = true;
        }
        if (state[i][i]) s = i;
    }
    bool ret = true;
    dfs (s);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ret = false;
            break;
        }
    }
    if (ret) {
        memset(vis, false, sizeof(vis));
        dfs(s, true);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ret = false;
                break;
            }
        }
    }
    if (ret) cout << "YES" << endl;
    else cout << "NO" << endl;
}