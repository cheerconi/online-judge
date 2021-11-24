#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <memory.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long double LD;
typedef long long LL;
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#ifdef LOCAL
#define DEBUG(x) { cerr << "# " << #x << ": " << x << endl;}
#else
#define DEBUG(x)
#endif
mt19937_64 mt(time(0));
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/
const int mod = 1e9 + 7;
const int MAXN = 2e5 + 10;
LL fact[MAXN], inv[MAXN], pow2[MAXN];

LL power(LL base, int p) {
    base = base % mod;
    LL ret = 1;
    while (p) {
        if (p & 1) ret = ret * base % mod;
        base = base * base % mod;
        p >>= 1;
    }
    return ret;
}
LL combine(int n, int k) {
    LL ret = fact[n] * inv[k] % mod;
    return ret * inv[n-k] % mod;
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n; cin >> n;
    pow2[0] = 1;
    fact[0] = 1;
    int a = 0, b = 0, num;
    for (int i = 1; i <= n; i++) {
        pow2[i] = pow2[i-1] * 2 % mod;
        fact[i] = fact[i-1] * i % mod;
        cin >> num;
        if (num % 2 == 1) continue;
        num /= 2;
        if (num % 2 == 1) a++;
        else b++;
    }
    inv[a] = power(fact[a], mod-2);
    for (int i = a-1; i >= 0; i--) {
        inv[i] = inv[i+1] * (i+1) % mod;
    }
    LL tmp = 0;
    for (int i = 1; i <= a; i += 2) {
        tmp = (tmp + combine(a, i)*pow2[b] % mod) % mod;
    }
    LL ret = (pow2[n] - 1 + mod) % mod;
    ret = (ret - b + mod) % mod;
    ret = (ret - tmp + mod) % mod;
    cout << ret << '\n';






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
