#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <assert.h>
using namespace std;
typedef long long LL;
const int MAXN = 200000 + 10;
int ban[MAXN];
LL inv[MAXN];
vector<LL> primes;

void make_table(LL mod) {
    for (LL i = 2; i*i <= mod; i++) {
        if (mod % i == 0) {
            primes.push_back(i);
            while (mod % i == 0) mod /= i;
        }
    }
    if (mod != 1) primes.push_back(mod);
}

LL gcd (LL a, LL b, LL & x, LL & y) {
    LL d = a;
    if (b != 0) {
        d = gcd(b, a%b, y, x);
        y -= (a/b)*x;
    }
    else {
        x = 1;
        y = 0;
    }
    return d;
}

int main() {
//    freopen("output.txt", "w", stdout);
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    unordered_map<LL, LL> dp;
    unordered_map<LL, vector<LL> > nodes;
    LL n, mod, val;
    cin >> n >> mod;
    LL m = mod;
    make_table(mod);
    for (int i = 0; i < n; i++) {
        cin >> val;
        ban[val] = 1;
    }
    LL a, b;
    for (int i = 0; i < m; i++) {
        LL val = gcd(mod, i, a, b);
        b = b % mod;
        inv[i] = (b + mod) % mod;
        if (ban[i] == 0) nodes[val].push_back(i);
    }
    dp[1] = nodes[1].size();
    queue<LL> q;
    q.push(1);
    ban[1] = -1;
    while (!q.empty()) {
        LL cur = q.front();
        q.pop();
        for (LL p : primes) {
            if (mod % (p*cur) != 0) continue;
            if (ban[p*cur] != -1) {
                q.push(p*cur);
                ban[p*cur] = -1;
            }
            dp[p*cur] = max(dp[p*cur], (LL)nodes[p*cur].size()+dp[cur]);
        }
    }
    vector<LL> idx(1, m);
    while (m != 1) {
        for (LL p : primes) {
            if (m % p == 0 && dp[m/p] + nodes[m].size() == dp[m]) {
                idx.push_back(m / p);
                m /= p;
            }
        }
    }
    vector<LL> ret;
    LL cur = 1;
    for (int i = idx.size()-1; i >= 0; i--) {
        if (nodes[idx[i]].empty()) continue;
        LL tmp = idx[i] / gcd(mod, cur, a, b);
        ret.push_back(tmp * inv[tmp*cur%mod] % mod * (nodes[idx[i]][0] / idx[i]) % mod);
        cur  = cur * ret.back() % mod;
        for (int j = 1; j < nodes[idx[i]].size(); j++) {
            LL tmp = inv[cur] * (nodes[idx[i]][j] / idx[i]) % mod;
            ret.push_back(tmp);
            cur = cur * tmp % mod;
        }
    }
    cout << ret.size() << endl;
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i];
        if (i+1 == ret.size()) cout << endl;
        else cout << ' ';
    }

    return 0;
}