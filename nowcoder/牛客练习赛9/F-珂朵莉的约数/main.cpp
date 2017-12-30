#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
const int MAXN = 100000 + 10;
const int MAXV = 1000000 + 10;
int factor[MAXV];
int ret[MAXN], idx[MAXN];
int dp[MAXN][170], inv[MAXV], eig[MAXN];
int cur[MAXV];
unordered_map<int, int> table;
int block, a[MAXN], b[MAXN];

bool cmp(int i, int j) {
    if (a[i]/block != a[j]/block) return a[i]/block < a[j]/block;
    return b[i] < b[j];
}

int power(LL base, int p) {
    LL ret = 1;
    while (p) {
        if (p & 1) ret = base * ret % mod;
        base = base * base % mod;
        p >>= 1;
    }
    return ret;
}
void build_table() {
    for (LL i = 2; i < MAXV; i++) {
        if (factor[i] != 0) continue;
        for (LL j = i*i; j < MAXV; j += i) {
            if (factor[j] == 0) factor[j] = i;
        }
    }
    for (int i = 1; i < MAXV; i++) {
        inv[i] = power(i, mod-2);
    }
    int id = 0;
    for (int i = 2; i < 1000; i++) {
        if (factor[i] == 0) {
            table[i] = id++;
        }
    }

}

int main() {
//    freopen("test.txt", "r", stdin);
    build_table();
    int n, m, val;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &val);
        for (int j = 0; j < 170; j++) dp[i][j] = dp[i-1][j];
        while (factor[val] != 0) {
            if (factor[val] > 1000) {
                eig[i] = factor[val];
            }
            else dp[i][table[factor[val]]]++;
            val /= factor[val];
        }
        if (val != 1) {
            if (val > 1000) eig[i] = val;
            else dp[i][table[val]]++;
        }
    }
    for (int i = 0; i < m; i++) {
        idx[i] = i;
        scanf("%d%d", a+i, b+i);
    }
    block = sqrt(m) + 1;
    sort(idx, idx+m, cmp);
    LL tmp = 1;
    int curX = 0, curY = 0;
    for (int i = 0; i < m; i++) {
        int x = a[idx[i]];
        int y = b[idx[i]];
        while (x != curX || y != curY) {
            if (curX < x && curX+1 <= curY) {
                if (eig[curX] != 0) {
                    tmp = tmp * inv[cur[eig[curX]]+1] % mod;
                    cur[eig[curX]]--;
                    tmp = tmp * (cur[eig[curX]]+1) % mod;
                }
                curX++;
            }
            if (curX > x) {
                curX--;
                if (eig[curX] != 0) {
                    tmp = tmp * inv[cur[eig[curX]]+1] % mod;
                    cur[eig[curX]]++;
                    tmp = tmp * (cur[eig[curX]]+1) % mod;
                }
            }
            if (curY < y) {
                curY++;
                if (eig[curY] != 0) {
                    tmp = tmp * inv[cur[eig[curY]]+1] % mod;
                    cur[eig[curY]]++;
                    tmp = tmp * (cur[eig[curY]]+1) % mod;
                }
            }
            if (curY > y && curY-1 >= curX) {
                if (eig[curY] != 0) {
                    tmp = tmp * inv[cur[eig[curY]]+1] % mod;
                    cur[eig[curY]]--;
                    tmp = tmp * (cur[eig[curY]] + 1) % mod;
                }
                curY--;
            }
        }
        ret[idx[i]] = tmp;
        for (int j = 0; j < 170; j++) {
            ret[idx[i]] = 1LL * ret[idx[i]] * (dp[y][j] - dp[x-1][j] + 1) % mod;
        }
    }
    for (int i = 0; i < m; i++) {
        printf("%d\n", ret[i]);
    }

    return 0;
}