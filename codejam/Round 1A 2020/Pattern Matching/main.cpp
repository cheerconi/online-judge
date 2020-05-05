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

bool update(string& cur, string& a) {
  if (cur.size() >= a.size()) {
    return a == cur.substr(0, a.size());
  }
  if (cur != a.substr(0, cur.size())) return false;
  cur = move(a);
  return true;
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
    int n; cin >> n;
    bool flag = true;
    string pre, suf, mid;
    for (int i = 0; i < n; i++) {
      string cur; cin >> cur;
      if (!flag) continue;
      int j = 0;
      for (; j < cur.size(); j++) {
        if (cur[j] == '*') break;
      }
      string tmp = cur.substr(0, j);
      if (!update(pre, tmp)) flag = false;
      int k = cur.size() - 1;
      for (; k >= 0; k--) {
        if (cur[k] == '*') break;
      }
      tmp = cur.substr(k+1);
      reverse(tmp.begin(), tmp.end());
      if (flag && !update(suf, tmp)) flag = false;
      if (flag) {
        for (int s = j; s < k; s++) {
          if (cur[s] != '*') mid.push_back(cur[s]);
        }
      }
    }
    cout << "Case #" << cs << ": ";
    if (flag) {
      reverse(suf.begin(), suf.end());
      cout << pre + mid + suf << '\n';
    }
    else cout << "*\n";
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
