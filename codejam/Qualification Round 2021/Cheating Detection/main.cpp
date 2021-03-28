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
string ans[100];
int rk[10000], cnt_q[10000], cnt_p[100];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int T, _; cin >> T >> _;
  for (int cs = 1; cs <= T; cs++) {
    memset(cnt_q, 0, sizeof(cnt_q));
    memset(cnt_p, 0, sizeof(cnt_p));
    for (int i = 0; i < 100; i++) {
      cin >> ans[i];
      for (int j = 0; j < 10000; j++) {
        if (ans[i][j] == '1') {
          cnt_q[j]++;
          cnt_p[i]++;
        }
      }
    }
    for (int i = 0; i < 10000; i++) rk[i] = i;
    sort(rk, rk+10000, [](int i, int j){
      return cnt_q[i] < cnt_q[j];
    });
    int idx = 0;
    double diff = 0;
    for (int i = 0; i <100; i++) {
      LL cur = 0;
      LL ones = 0;
      for (int j = 0;j < 10000; j++) {
        int k = rk[j];
        if (ans[i][k] == '0') {
          cur += ones;
        } else {
          ones++;
        }
        double tmp = (double)cur / ones / (10000-ones);
        if (diff < tmp) {
          diff = tmp;
          idx = i;
        }
      }
    }

    cout << "Case #" << cs << ": " << 1 + idx << endl;


  }







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
