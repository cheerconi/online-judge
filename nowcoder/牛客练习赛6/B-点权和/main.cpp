#include <iostream>
using namespace std;
typedef long long LL;
const int mod = 19260817;
struct Node{
    LL val = 0;
    LL tot = 0;
    LL share = 0;
    LL dad = 0;
    LL sons = 0;
};
const int MAXN = 100000 + 10;
Node tree[MAXN];
const int ch_top = 4e8+3;
char ch[ch_top], *now_r = ch-1;
inline int read() {
    while (*++now_r < '0');
    register int x = *now_r - '0';
    while (*++now_r >= '0') x = x*10 + *now_r - '0';
    return x;
}

int main() {
//    freopen("test.txt", "r", stdin);
    fread(ch, 1, ch_top, stdin);
    int n, m, d;
    n = read(); m = read();
    for (int i = 2; i <= n; i++) {
        d = read();
        tree[i].dad = d;
        tree[d].sons++;
    }
    LL ret = 0;
    for (LL i = 1; i <= m; i++) {
        d = read();
        int dd = tree[d].dad;
        tree[d].val++;
        ret = (ret + i * tree[d].val) % mod;
        if (dd != 0) {
            ret = (ret + i * tree[dd].share) % mod;
            tree[dd].val++;
            ret = (ret + i * tree[dd].val) % mod;
            tree[dd].tot++;
            if (tree[dd].dad != 0) {
                ret = (ret + i * tree[tree[dd].dad].share) % mod;
                tree[tree[dd].dad].tot++;
            }
        }
        tree[d].tot = (tree[d].tot + tree[d].sons) % mod;
        ret = (ret + i * tree[d].tot) % mod;
        tree[d].share++;
    }
    cout << ret << endl;
    return 0;
}