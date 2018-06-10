#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pll;
const int MAXN = 100 + 10;
vector<int> edges[MAXN];
bool used[MAXN];
int x, y;

pll solve (int root, bool bad = false) {
    LL ret = 1;
    memset(used, false, sizeof(used));
    queue<int> q;
    LL layer = 0;
    q.push(root); used[root] = true;
    while (!q.empty()) {
        layer++;
        int sz = q.size();
        int m = 0;
        for (int i = 0; i < sz; i++) {
            int cur = q.front(); q.pop();
            int cnt = 0;
            for (int nxt : edges[cur]) {
                if (used[nxt]) continue;
                if (bad) {
                    if (x == cur && y == nxt) continue;
                    if (y == cur && x == nxt) continue;
                }
                cnt++;
                q.push(nxt); used[nxt] = true;
            }
            m = max(m, cnt);
        }
        if (m != 0) ret = ret * m;
        if (ret < 0)  return {500LL, 0LL};
    }
    return {layer, ret};

}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    pll ret = {500LL, 0LL};
    for (int i = 1; i <= n; i++) {
        ret = min(ret, solve(i));
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < edges[i].size(); j++) {
            if (i > edges[i][j]) continue;
            x = i; y = edges[i][j];
            edges[n+1].push_back(x);
            edges[n+1].push_back(y);
            edges[x].push_back(n+1);
            edges[y].push_back(n+1);
            auto tmp = solve(n+1, true);
            tmp.first--;
            ret = min(ret, tmp);
            edges[n+1].clear();
            edges[x].pop_back();
            edges[y].pop_back();
        }
    }
    cout << ret.first << ' ' << ret.second << endl;




    return 0;
}