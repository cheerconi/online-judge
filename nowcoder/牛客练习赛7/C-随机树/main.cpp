#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;
const int mod = 1e9 + 7;
vector<int> edges[MAXN];
int L[MAXN], R[MAXN], tree[MAXN][6];
char s[20];
int p[] = {2, 3, 5, 7, 11, 13};
int tot = 1;
void dfs(int root) {
    L[root] = tot++;
    for (int son : edges[root])  dfs(son);
    R[root] = tot-1;
}
inline int lowbit(int i) {
    return i&(-i);
}
void add (int i, int j, int val) {
    while (i < tot) {
        tree[i][j] += val;
        i += lowbit(i);
    }
}
int find (int i, int j) {
    int ret = 0;
    while (i > 0) {
        ret += tree[i][j];
        i -= lowbit(i);
    }
    return ret;
}

int power(int base, int n) {
    int ret = 1;
    while (n) {
        if (n&1) ret = 1LL * base * ret % mod;
        n >>= 1;
        base = 1LL * base * base % mod;
    }
    return ret;

}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, a, b, q;
    cin >> n;
    for (int i = 1; i <= n-1; i++) {
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        for (int j = 0; j < 6; j++) {
            b = 0;
            while (a % p[j] == 0) {
                b++;
                a /= p[j];
            }
            add (L[i], j, b);
        }
    }
    cin >> q;
    int ret1, ret2;
    while (q--) {
        scanf("%s", s);
        if (s[0] == 'R') {
            scanf("%d", &a);
            ret1 = ret2 = 1;
            for (int i = 0; i < 6; i++) {
                b = find(R[a], i) - find(L[a]-1, i);
                ret1 = 1LL * ret1 * power(p[i], b) % mod;
                ret2 = 1LL * (b+1) * ret2 % mod;
            }
            printf("%d %d\n", ret1, ret2);

        }
        else {
            scanf("%d%d", &a, &b);
            for (int i = 0; i < 6; i++) {
                ret1 = 0;
                while (b % p[i] == 0) {
                    ret1++;
                    b /= p[i];
                }
                add(L[a], i, ret1);
            }
        }
    }

    return 0;
}