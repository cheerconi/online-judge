#include <iostream>
#include <queue>
#include <memory.h>
#include <vector>
using namespace std;
const int MAXN = 22;
bool vis[1<<MAXN];
int op[1<<MAXN], state[MAXN], pre[1<<MAXN], n, m;
vector<int> ret;

void solve () {
    int ones = (1 << n) - 1;
    memset(op, -1, sizeof(op));
    memset(pre, -1, sizeof(pre));
    queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(state[i]);
        op[state[i]] = i;
        vis[state[i]] = true;
        if (state[i] == ones) return;
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 0; i < n; i++) {
            if (cur & (1<<i)) {
                int tmp = cur | state[i];
                if (!vis[tmp]) {
                    op[tmp] = i;
                    vis[tmp] = true;
                    pre[tmp] = cur;
                    if (tmp == ones) return;
                    q.push(tmp);

                }
            }
        }
    }
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int a, b;
    cin >> n >> m;
    if (m == n*(n-1)/2) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) state[i] = (1<<i);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        state[a] |= 1 << b;
        state[b] |= 1 <<a ;
    }
    solve();
    int cur = (1<<n) - 1;
    while (cur != -1) {
        ret.push_back(op[cur]);
        cur = pre[cur];
    }
    n = ret.size();
    cout << n << endl;
    for (int i = n-1; i >= 0; i--) {
        cout << ret[i]+1;
        if (i == 0) cout << endl;
        else cout << ' ';
    }
    return 0;
}