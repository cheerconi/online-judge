#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;
const int MAXN = 1000 + 10;
bool used[MAXN];
int match[MAXN];
vector<int> edges[MAXN];

bool dfs(int cur) {
    used[cur] = true;
    for (int i = 0; i < edges[cur].size(); i++) {
        int nxt = edges[cur][i];
        int u = match[nxt];
        if (u == -1 || (!used[u] && dfs(u))) {
            match[nxt] = cur;
            match[cur] = nxt;
            return true;
        }
    }
    return false;

}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k, a, b;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        edges[a].push_back(b+n);
        edges[b+n].push_back(a);
    }
    memset(match, -1, sizeof(match));
    int cnt = 0;
    for (int i = 1; i <= 2*n; i++) {
        if (match[i] == -1) {
            memset(used, false, sizeof(used));
            if (dfs (i)) cnt++;
        }
    }
    cout << cnt << endl;
}
