#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 400000 + 10;
LL val[MAXN][21], sum[MAXN][21];
int edge[MAXN][21], seq[MAXN][21];

int find(int cur, LL w) {
    if (cur == 0 || val[cur][0] >= w) return cur;
    for (int i = 20; i >= 0; i--) {
        int tmp = edge[cur][i];
        if (tmp == 0) continue;
        if (val[cur][i] < w) return find(edge[edge[cur][i]][0], w);
    }
}

void add (int cur, int par, LL w) {
    edge[cur][0] = par;
    val[cur][0] = sum[cur][0] = w;
    for (int i = 1; i <= 20; i++) {
        int pre = edge[cur][i-1];
        if (pre == 0) break;
        val[cur][i] = max(val[cur][i-1], val[pre][i-1]);
        edge[cur][i] = edge[pre][i-1];
    }



}
int query(int cur, LL bound) {

}

int main() {
    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int cs; cin >> cs;
    LL last = 0, p, q, cmd, cnt = 1;
    while (cs--) {
        cin >> cmd >> p >> q;
        p = p^last;
        q = q^last;
        if (cmd == 1) {
            add(++cnt, p, q);
        }
        else {
            last = query(p, q);
            cout << last << '\n';
        }
    }
}