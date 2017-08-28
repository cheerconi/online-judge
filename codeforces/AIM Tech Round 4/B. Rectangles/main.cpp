#include <iostream>
using namespace std;
typedef long long LL;
const int MAXN = 55;
int graph[MAXN][MAXN];

LL power(int n) {
    LL base = 2;
    LL ret = 1;
    while (n) {
        if (n & 1) ret *= base;
        n >>= 1;
        base *= base;
    }
    return ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, m;
    LL ret = 0;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            scanf("%d", &graph[i][j]);
            cnt += graph[i][j];
        }
        ret += power(cnt) + power(m-cnt) - 2;
    }
    for (int j = 0; j < m; j++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += graph[i][j];
        }
        ret += power(cnt) + power(n-cnt) - 2;
    }
    ret -= m*n;
    cout << ret << endl;
    return 0;
}