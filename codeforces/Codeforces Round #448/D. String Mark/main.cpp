#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 1e6 + 10;
int fact[MAXN], inv[MAXN], cnt[26];

int power(int base, int p) {
    int ret = 1;
    while (p) {
        if (p&1) ret = 1LL * ret * base % mod;
        p >>= 1;
        base = 1LL * base * base % mod;
    }
    return ret;
}
int solve(string & a, string & b){
    memset(cnt, 0, sizeof(cnt));
    int n = a.size();
    int ret = 0, cur = 1;
    for (char c : a) {
        cnt[c-'a']++;
    }
    for (int i = 0; i < 26; i++) cur = 1LL * cur * inv[cnt[i]] % mod;

    for (int i = 0; i < n; i++) {
        int coeff = fact[n-i-1];
        int tot = 0;
        for (int j = 0; j < b[i]-'a'; j++) {
            tot += cnt[j];
        }
        ret = (ret + 1LL * coeff * tot % mod * cur % mod) % mod;
        if (cnt[b[i]-'a'] == 0) break;
        cur = 1LL * cur * cnt[b[i]-'a'] % mod;
        cnt[b[i]-'a']--;
    }
    return ret;
}

void make_table(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = 1LL * fact[i-1] * i % mod;
    inv[n] = power(fact[n], mod-2);
    for (int i = n-1; i >= 0; i--) inv[i] = 1LL * inv[i+1] * (i+1) % mod;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    make_table(a.size());
    int ret = solve(a, b);
    ret -= solve(a, a);
    if (ret < 0) ret += mod;
    ret--;
    if (ret < 0) ret += mod;
    cout << ret << endl;
    return 0;
}