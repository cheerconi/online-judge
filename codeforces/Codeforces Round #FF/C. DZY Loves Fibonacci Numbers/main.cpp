#include <iostream>
#define leftnode (node<<1)
#define rightnode ((node<<1)|1)
#define getmid ((left+right)>>1)
using namespace std;
typedef long long LL;
const int MAXN = 300000 + 10;
const int mod = 1e9 + 9;
LL sqrt5 = 383008016, invsqrt5, a, b, inv[2];
int tree[2][MAXN<<2], mine[2][MAXN<<2], dp[MAXN], pow[2][MAXN];

int power (LL base, LL p) {
    LL ret = 1;
    while (p) {
        if (p & 1) ret = base * ret % mod;
        base = base * base % mod;
        p >>= 1;
    }
    return ret;
}

void make_table(int n) {
    invsqrt5 = power(sqrt5, mod-2);
    a = (1+sqrt5) * power(2, mod-2) % mod;
    b = (mod+1-sqrt5) % mod * power(2, mod-2) % mod;
    pow[0][0] = pow[1][0] = 1;
    for (int i = 1; i <= n; i++) {
        pow[0][i] = 1LL * pow[0][i-1] * a % mod;
        pow[1][i] = 1LL * pow[1][i-1] * b % mod;
    }
    inv[0] = power((a-1+mod)%mod, mod-2);
    inv[1] = power((b-1+mod)%mod, mod-2);

}

int get_sum (LL val, LL len, int idx) {
    LL ret = val * ((pow[idx][len] - 1 + mod) % mod) % mod;
    ret = ret * inv[idx] % mod;
    return ret;
}
void update(int node, int left, int right, int i, int j, LL val, int idx) {
    if (right < i || j < left) return;
    if (i <= left && right <= j) {
        val = val * pow[idx][left - i] % mod;
        mine[idx][node] = (val + mine[idx][node]) % mod;
        tree[idx][node] = (get_sum(val, right-left+1, idx) + tree[idx][node]) % mod;
        return;
    }
    int mid = getmid;
    update(leftnode, left, mid, i, j, val, idx);
    update(rightnode, mid+1, right, i, j, val, idx);
    tree[idx][node] = (tree[idx][leftnode] + tree[idx][rightnode]) % mod;
    tree[idx][node] = (tree[idx][node] + get_sum(mine[idx][node], right-left+1, idx)) % mod;
}
int query(int node, int left, int right, int i, int j, int idx) {
    if (right < i || j < left) return 0;
    if (i <= left && right <= j) return tree[idx][node];
    int mid = getmid;
    LL ret = query(leftnode, left, mid, i, j, idx);
    ret = (ret + query(rightnode, mid+1, right, i, j, idx)) % mod;
    int x = max(left, i);
    int y = min(right, j);
    LL val = 1LL * mine[idx][node]*pow[idx][x-left] % mod;
    ret = (ret + get_sum(val, y-x+1, idx)) % mod;
    return ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL n, cs, cmd, l, r, ret;
    cin >> n >> cs;
    make_table(n);
    for (int i = 1; i <= n; i++) {
        cin >> dp[i];
        dp[i] = (dp[i] + dp[i-1]) % mod;
    }
    while (cs--) {
        cin >> cmd >> l >> r;
        if (cmd == 1) {
            update(1, 1, n, l, r, a, 0);
            update(1, 1, n, l ,r, b, 1);
        }
        else {
            ret = query(1, 1, n, l ,r, 0) - query(1, 1, n, l, r, 1);
            ret = (ret + mod) % mod;
            ret = ret * invsqrt5 % mod;
            ret = (dp[r] - dp[l-1] + mod + ret) % mod;
            cout << ret << '\n';
        }
    }
    return 0;
}