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
LL nums[MAXN][2];
LL eaten[MAXN][2];

LL solve(LL tot, LL a, LL b) {
    LL half = tot / 2;
    if (a <= half && half <= b) return half;
    if (tot % 2 == 1 && a <= half+1 && half+1 <= b) return half+1;
    if (abs(tot-a-a) <= abs(tot-b-b)) return a;
    return b;
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        LL a = 0, b = 0;
        LL tot = 0;
        LL suma = 0;
        for (int i = 0; i < n; i++) {
            eaten[i][0] = 0;
            eaten[i][1] = 0;
            cin >> nums[i][0] >> nums[i][1];
            suma += nums[i][0];
            tot += nums[i][0] + nums[i][1] - m;
            LL mi = max(0LL, nums[i][0] - m);
            LL ma = min(nums[i][0] + nums[i][1] - m, nums[i][0]);
            a += mi;
            b += ma;
        }
        LL target = suma - solve(tot, a, b);
        LL done = 0;
        for (int i = 0; i < n; i++) {
            eaten[i][0] = min((LL)m, nums[i][0]);
            eaten[i][1] = m - eaten[i][0];
            done += eaten[i][0];
        }
        assert(done >= target);
        for (int i = 0; i < n && done != target; i++) {
            LL diff = min(done - target, eaten[i][0]);
            diff = min(diff, nums[i][1] - eaten[i][1]);
            eaten[i][0] -= diff;
            eaten[i][1] += diff;
            done -= diff;
        }
        cout << abs(tot - 2*(suma - target)) << '\n';
        for (int i = 0; i < n; i++) {
            cout << eaten[i][0] << ' ' << eaten[i][1] << '\n';
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
