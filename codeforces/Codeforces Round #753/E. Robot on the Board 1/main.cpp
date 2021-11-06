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






int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int T; cin >> T;
    while (T--) {
        int n[2];
        cin >> n[0] >> n[1];
        string s; cin >> s;
        int ret[2] = {1, 1};
        int ma[2] = {};
        int mi[2] = {};
        int p[2] = {};
        bool done = false;
        for (char c : s) {
            if (c == 'R') p[1]++;
            else if (c == 'L') p[1]--;
            else if (c == 'D') p[0]++;
            else if (c == 'U') p[0]--;
            for (int j = 0; j < 2; j++) {
                ma[j] = max(ma[j], p[j]);
                mi[j] = min(mi[j], p[j]);
                if (ma[j] - mi[j] + 1 > n[j]) {
                    done = true;
                    break;
                }
            }
            if (done) break;
            ret[0] = -mi[0] + 1;
            ret[1] = -mi[1] + 1;
        }
        cout << ret[0] << ' ' << ret[1] << '\n';

    }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
