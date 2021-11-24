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
const int MAXN = 2e5 + 10;
int a[MAXN], b[MAXN];
const int MAXV = 1e6 + 10;
LL k[MAXV], bias[MAXV];
LL c[MAXN], d[MAXN];






int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int m = 1e6;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = b[i];
        d[i] = b[i];
    }
    c[1] = 1;
    d[1] = m;
    for (int i = 1; i <= n; i++) {
        if (c[i] == d[i]) {
            bias[0] += abs(a[i] - c[i]);
        } else if (c[i] > d[i]) {
            if (d[i] >= a[i]) {
                k[0]--;
                bias[0] += c[i] - a[i] + 1;
            } else if (a[i] >= c[i]) {
                k[0]++;
                bias[0] += a[i] - c[i] - 1;
            } else {
                k[0]--;
                bias[0] += c[i] - a[i] + 1;
                int idx = c[i] - a[i] + 1;
                k[idx] += 2;
                bias[idx] -= c[i] - a[i] + 1;
                bias[idx] -= idx;
            }
        } else {
            if (d[i] <= a[i]) {
                k[0]--;
                bias[0] += a[i] - c[i] + 1;
            } else if (c[i] >= a[i]) {
                k[0]++;
                bias[0] += c[i] - a[i] - 1;
            } else {
                k[0]--;
                bias[0] += a[i] - c[i] + 1;
                int idx = a[i] - c[i] + 1;
                k[idx] += 2;
                bias[idx] -= a[i] - c[i] + 1;
                bias[idx] -= idx;
            }
        }
        for (int j = i+i; j <= n; j += i) {
            c[j] += a[i] - c[i];
            d[j] += a[i] - d[i];
        }
    }
    for (int i = 1; i <= m; i++) {
        k[i] += k[i-1];
        bias[i] += bias[i-1];
    }
    int q; cin >> q;
    while (q--) {
        int idx; cin >> idx;
        cout << k[idx] * idx + bias[idx] << '\n';
    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
