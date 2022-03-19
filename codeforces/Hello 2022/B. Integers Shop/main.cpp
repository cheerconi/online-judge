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
const int MAXN = 1e5 + 10;
LL a[MAXN], b[MAXN], c[MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int mi = 0, ma = 0;
        int xx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i] >> c[i];
            if (a[i] < a[mi]) {
                mi = i;
            } else if (a[i] == a[mi] && c[i] < c[mi]) {
                mi = i;
            }
            if (b[i] > b[ma]) {
                ma = i;
            } else if (b[i] == b[ma] && c[i] < c[ma]) {
                ma = i;
            }
            if (xx != -1) {
                if (a[xx] != a[mi] || b[xx] != b[ma]) {
                    xx = -1;
                }
            }
            if (a[i] == a[mi] && b[i] == b[ma] && (xx == -1 || c[xx] > c[i])) {
                xx = i;
            }
            LL ret = c[mi] + c[ma];
            if (xx != -1) ret = min(ret, c[xx]);
            cout << ret << '\n';
        }



    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
