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

LL my_sqrt(LL a) {
    double val = sqrt(a);
    LL ret = val;
    if (ret+1 - val < val - ret) return ret+1;
    return ret;
}

bool solve1(LL r, LL x, LL y) {
    for (LL rr = 0; rr <= r; rr++) {
        if (x > rr || x < -rr) continue;
        LL yy = my_sqrt(rr*rr - x*x);
        if (y == yy || y == -yy) return true;
    }
    return false;

}
bool solve2(LL r, LL x, LL y) {
    return my_sqrt(x*x + y*y) <= r;
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int T; cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        int r; cin >> r;
        LL ret = 0;
        for (int i = 0; i <= r; i++) {
            for (int j = 0; j <= r; j++) {
                bool ret1 = solve1(r, i, j) || solve1(r, j, i);
                bool ret2 = solve2(r, i, j);
                if (ret1 != ret2) ret++;
            }
        }
        cout << "Case #" << cs << ": " << ret * 4 << '\n';

    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
