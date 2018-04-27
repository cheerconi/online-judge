#include <iostream>
#include <random>
#include <vector>
#include <time.h>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int MAXN = 1e6 + 10;
LL id[MAXN], hsh[MAXN];
vector<int> edges[MAXN];
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
int main() {
//    freopen("test.txt", "r", stdin);
    mt19937_64 mt(time(0));
    int n, m, a, b;
    read(n); read(m);
    for (int i = 1; i <= n; i++) {
        id[i] = mt();
    }
    for (int i = 0; i < m; i++) {
        read(a); read(b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        sort(edges[i].begin(), edges[i].end(), greater<int>());
        for (int j : edges[i]) {
            hsh[i] ^= id[j];
        }
    }
    LL ret = 0;
    unordered_map<LL, int> table;
    for (int i = n; i >= 1; i--) {
        for (int j : edges[i]) {
            if (j < i) break;
            LL x = hsh[j] ^ id[i];
            LL y = hsh[i] ^ id[j];
            if (x == y) ret++;
        }
        auto it = table.find(hsh[i]);
        if (it != table.end()) {
            ret += it->second;
            it->second++;
        }
        else table[hsh[i]]++;
    }
    cout << ret << endl;


}