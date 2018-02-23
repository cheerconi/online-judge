#include <iostream>
using namespace std;
typedef long long LL;
const int MAXN = 400000  +10;
int par[MAXN][20];
LL sum[MAXN][20];
int cnt = 0;

void add (int p, LL w) {
    cnt++;
    sum[cnt][0] = w;
    for (int i = 19; i >= 0; i--) {
        if (sum[par[p][i]][0] < w) p = par[p][i];
    }
    if (sum[p][0] < w) p = par[p][0];
    for (int i = 0; i < 20; i++) {
        par[cnt][i] = p;
        if (i+1 < 20) sum[cnt][i+1] = sum[cnt][i] + sum[p][i];
        p = par[p][i];
    }
}
int query(int cur, LL w) {
    if (sum[cur][0] > w) return 0;
    for (int i = 19; i >= 0; i--) {
        if (sum[cur][i] <= w) {
            return (1<<i) + query(par[cur][i], w-sum[cur][i]);
        }
    }

}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int cs; cin >> cs;
    for (int i = 0; i < 20; i++) {
        sum[0][i] = 1e16;
    }
    add (0, 0);
    int cmd;
    LL p, q, last = 0;
    while (cs--) {
        cin >> cmd >> p >> q;
        p ^= last;
        q ^= last;
        if (cmd == 1) {
            add (p, q);
        }
        else {
            last = query(p, q);
            cout << last << '\n';
        }

    }
}