#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;

const int MAXN = 3e5 + 10;
vector<int> edges[MAXN];
LL sz[MAXN];
bool tag[MAXN];
void dfs (int cur, int par) {
    sz[cur] = 1;
    for (int nxt : edges[cur]) {
        if (nxt == par) continue;
        dfs (nxt, cur);
        tag[cur] |= tag[nxt];
        sz[cur] += sz[nxt];
    }
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL n, x, y, a, b;
    cin >> n >> x >> y;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    tag[y] = true;
    dfs(x, 0);
    LL ret = n * (n-1);
    LL tot = n;
    for (int nxt : edges[x]) {
        if (tag[nxt]) {
            tot -= sz[nxt];
            break;
        }
    }
    ret = ret - tot*sz[y];
    cout << ret << endl;
    return 0;
}