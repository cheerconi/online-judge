#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e6 + 10;
vector<int> edges[MAXN];
int par[MAXN][20], k;
bool tag[MAXN];

inline char get(void) {
    static char buf[100000], *S = buf, *T = buf;
    if (S == T) {
        T = (S = buf) + fread(buf, 1, 100000, stdin);
        if (S == T) return EOF;
    }
    return *S++;
}
inline void read(int &x) {
    static char c; x = 0; int sgn = 0;
    for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
    for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
    if (sgn) x = -x;
}

void dfs(int cur) {
    for (int nxt : edges[cur]) {
        if (nxt == par[cur][0]) continue;
        par[nxt][0] = cur;
        dfs (nxt);
    }
}
int up(int cur) {
    if (tag[cur]) return 0;
    for (int i = 19; i >= 0; i--) {
        if (par[cur][i] == 0) continue;
        if (!tag[par[cur][i]]) {
            if ((1<<i) > k) return k+1;
            return (1<<i)+up(par[cur][i]);
        }
    }
    return 1;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, m, a, b;
    read(n); read(m);
    for (int i = 1; i < n; i++) {
        read(a); read(b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(n);
    for (int i = 1; i <= 19; i++) {
        for (int cur = 1; cur <= n; cur++) {
            par[cur][i] = par[par[cur][i-1]][i-1];
        }
    }
    k = n - m - 1;
    tag[n] = true;
    for (int cur = n-1; cur >= 1 && k > 0; cur--) {
        if (tag[cur]) continue;
        if (up(cur) <= k) {
            int tmp = cur;
            while (!tag[tmp]) {
                tag[tmp] = true;
                k--;
                tmp = par[tmp][0];
            }
        }
    }
    for (int i = 1; i <= n && m > 0; i++) {
        if (!tag[i]) {
            printf("%d", i);
            m--;
            if (m == 0) printf("\n");
            else printf(" ");
        }
    }





}