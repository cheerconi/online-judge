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
const int mod = 998244353;
const int MAXN = 2e5 + 10;
int x[MAXN], y[MAXN];
int x2q[MAXN], y2q[MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int T; cin >> T;
    int baseq = 1;
    for  (int t = 1; t <= T; t++) {
        int n, m, k, q; cin >> n >> m >> k >> q;
        for (int i = baseq; i < q + baseq; i++) {
            cin >> x[i] >> y[i];
        }
        int totx = 0, toty = 0;
        map<int, bool> q2x, q2y;
        for (int i = q+baseq-1; i >= baseq; i--) {
            if (x2q[x[i]] < baseq) {
                x2q[x[i]] = i;
                q2x[i] = true;
                totx++;
                if (totx == n) break;
            }
            if (y2q[y[i]] < baseq) {
                y2q[y[i]] = i;
                q2y[i] = true;
                toty++;
                if (toty == m) break;
            }

        }
        LL ret = 1;
        for (int i = baseq; i < q+baseq; i++) {
            if (q2x[i] || q2y[i]) {
                ret = ret * k % mod;
            }
        }
        baseq += q;
        cout << ret << '\n';


    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
