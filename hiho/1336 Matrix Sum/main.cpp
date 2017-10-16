#include <iostream>
using namespace std;
typedef long long LL;
const int MAXN = 1000 + 10;
const int mod = 1e9 + 7;
int n;
LL dp[MAXN][MAXN];
inline int lowbit(int i) {
    return i&(-i);
}
void add (int a, int b, int val) {
    a++;
    b++;
    for (int i = a; i <= n; i += lowbit(i)) {
        for (int j = b; j <=n; j+= lowbit(j)) {
            dp[i][j] += val;
        }
    }
}
LL query(int a, int b) {
    a++;
    b++;
    LL sum = 0;
    for (int i = a; i > 0; i -= lowbit(i)) {
        for (int j = b; j > 0; j -= lowbit(j)) {
            sum += dp[i][j];
        }
    }
    return sum;
}
LL query(int a, int b, int c, int d) {
    LL ret = query(c, d) - query(a-1, d) - query(c, b-1) + query(a-1, b-1);
    while (ret < 0) ret += mod;
    ret = ret % mod;
    return ret;
}


int main() {
//    freopen("test.txt", "r", stdin);
    int q;
    scanf("%d%d", &n, &q);
    char s[20];
    int a, b, c, d;
    while (q--) {
        scanf("%s", s);
        if (s[0] == 'A') {
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
        }
        else {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            printf("%lld\n", query(a, b, c, d));
        }
    }
    return 0;
}