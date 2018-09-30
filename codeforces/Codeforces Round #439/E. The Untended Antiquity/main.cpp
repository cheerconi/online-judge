#include <iostream>
using namespace std;
typedef long long LL;

const int MAXN = 2500 + 10;
int n, m;

LL bit[MAXN][MAXN];

inline int lowbit(int a) {
    return a&(-a);
}

int update (int x, int y, LL val) {
    for (int i = x; i <= n; i += lowbit(i)) {
        for (int j = y; j <= m; j += lowbit(j)) {
            bit[i][j] += val;
        }
    }
}
void update (int x1, int y1, int x2, int y2, LL val) {
    update(x1, y1, val);
    update(x2+1, y1, -val);
    update(x1, y2+1, -val);
    update(x2+1, y2+1, val);
}

LL query(int x, int y) {
    LL ret = 0;
    for (int i = x; i >= 1; i -= lowbit(i)) {
        for (int j = y; j >= 1; j -= lowbit(j)) {
            ret += bit[i][j];
        }
    }
    return ret;
}
LL encode(int x1, int y1, int x2, int y2) {
    LL val = x1*MAXN + y1;
    val  = val * MAXN + x2;
    val = x2 * MAXN + y2;
    return val;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int q, type, x1, y1, x2, y2;
    scanf("%d%d%d", &n, &m, &q);
    while (q--) {
        scanf("%d%d%d%d%d", &type, &x1, &y1, &x2, &y2);
        if (type == 1) {
            update(x1, y1, x2, y2, encode(x1, y1, x2, y2));
        }
        else if (type == 2) {
            update(x1, y1, x2, y2, -encode(x1, y1, x2, y2));
        }
        else {
            if (query(x1, y1) == query(x2, y2)) printf("Yes\n");
            else printf("No\n");
        }
    }
}