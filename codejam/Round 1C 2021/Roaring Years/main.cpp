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

bool gt(const string& s1, const string& s2) {
  if (s1.size() != s2.size()) return s1.size() > s2.size();
  return s1 > s2;
}

void solve(LL cur, const string& s, string& ret) {
  string tmp = to_string(cur);
  if (tmp.size()*2 > ret.size()) return;
  for (LL j = cur+1; true; j++) {
    tmp += to_string(j);
    if (gt(tmp, s)) break;
  }
  if (gt(ret, tmp)) ret = tmp;
}

LL solve(LL val) {
  string s = to_string(val);
  string ret(19, '9');
  for (LL i = 1; true; i *= 10) {
    solve(i, s, ret);
    if (to_string(i).size() * 2 >= s.size()) break;
  }
  for (LL i = 1; i <= 10000; i++) {
    solve(i, s, ret);
  }
  for (LL i = 999; true; i = i*10 + 9) {
    for (int j = 0; j <= 10; j++) {
      solve(i-j, s, ret);
    }
    if (to_string(i).size()*2 >= s.size()+1) break;
  }
  for (int i = 0; i < s.size(); i++) {
    LL cur = stoll(s.substr(0, i+1));
    for (int j = 0; j <= 10; j++) {
      solve(cur+j, s, ret);
    }
  }
  LL res = stoll(ret);
  return res;
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
    LL val; cin >> val;
    cout << "Case #" << cs << ": " << solve(val) << endl;
  }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
