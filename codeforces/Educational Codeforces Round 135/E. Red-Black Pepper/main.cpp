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
const int MAXN = 3e5 + 10;
int n, a[MAXN], b[MAXN], idx[MAXN], max_idx;
LL dp[MAXN];

vector<LL> my_gcd(LL x, LL y) {
    bool inverse = false;
    if (x < y) {
        swap(x, y);
        inverse = true;
    }
    if (y == 0) {
        vector<LL> ret = {x, 1, 0};
        if (inverse) {
            swap(ret[1], ret[2]);
        }
        return ret;
    }
    LL k = x / y;
    vector<LL> tmp = my_gcd(y, x-k*y);
    vector<LL> ret = {tmp[0], tmp[2], tmp[1]-tmp[2]*k};
    if (inverse) {
        swap(ret[1], ret[2]);
    }
    return ret;
}

LL solve(int x, int y) {
    vector<LL> tmp = my_gcd(x, y);
    if (n % tmp[0] != 0) return -1;
    LL k = n / tmp[0];
    LL k1 = k * tmp[1];
    LL p = y / tmp[0];
    k1 = (k1 % p + p) % p;
    if (k1 * x > n) return -1;
    if (k1*x >= max_idx) return dp[k1*x];
    LL coeff = (max_idx-k1*x) / (p*x);
    LL ret = dp[k1 * x +coeff*p * x];
    coeff++;
    if ((k1+coeff*p) * x <= n) ret = max(ret, dp[(k1+coeff*p) * x]);
    return ret;
}



int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        dp[0] += b[i];
        idx[i] = i;

    }
    sort(idx, idx+n, [](int i, int j) {
        return a[i]-b[i] > a[j]-b[j];
    });
    for (int i = 0; i < n; i++) {
        int id = idx[i];
        dp[i+1] = dp[i] + a[id] - b[id];
    }
    for (int i = 1; i <= n; i++) {
        if (dp[max_idx] < dp[i]) {
            max_idx = i;
        }
    }
    int m; cin >> m;
    while (m--) {
        int x, y; cin >> x >> y;
        cout << solve(x, y) << '\n';
    }








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
