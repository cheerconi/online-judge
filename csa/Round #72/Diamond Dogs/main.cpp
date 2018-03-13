#include <iostream>
#include <algorithm>
#define leftnode (node<<1)
#define rightnode ((node<<1)|1)
#define getmid ((left+right)>>1)
using namespace std;
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

const int MAXN = 1e5 + 10;
const int MAXB = 20;
int dat[MAXN][MAXB], idx[MAXN], a[MAXN], b[MAXN], n;

void make_table() {
    for (int i = 1; i <= n; i++) {
        read(dat[i][0]);
    }
    for (int j = 1; j < MAXB; j++) {
        for (int i = 1; i <= n; i++) {
            if ((1<<(j-1))+i > n) break;
            dat[i][j] = max(dat[i][j-1], dat[(1<<(j-1))+i][j-1]);
        }
    }
}
int query(int i, int j) {
    int b = MAXB-1;
    while (b > 0) {
        if ((1<<b) <= j-i+1) break;
        b--;
    }
    return max(dat[i][b], dat[j-(1<<b)+1][b]);
}

bool cmp(int i, int j) {
    if (a[i] == a[j] && b[i] == b[j]) return false;
    if (a[i] <= a[j] && b[j] <= b[i]) return false;
    if (a[j] <= a[i] && b[i] <= b[j]) return true;
    int ai = a[i], bi = b[i], aj = a[j], bj = b[j];
    if (b[i] >= a[j] && b[j] >= a[i]) {
        if (a[i] < a[j]) {
            ai = a[i];
            bi = a[j]-1;
            aj = b[i]+1;
            bj = b[j];
        }
        else {
            aj = a[j];
            bj = a[i]-1;
            ai = b[j]+1;
            bi = b[i];
        }
    }

    int x = query(ai, bi);
    int y = query(aj, bj);
    return x < y;
}

int main() {
//    freopen("test.txt", "r", stdin);
    read(n);
    make_table();
    int m; read(m);
    for (int i = 1; i <= m; i++) {
        read(a[i]); read(b[i]);
        idx[i] = i;
    }
    sort(idx+1, idx+1+m, cmp);
    for (int i = 1; i <= m; i++) {
        printf("%d", idx[i]);
        if (i == m) printf("\n");
        else printf(" ");
    }

    return 0;
}