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
  string s; cin >> s;
  int zero = 0, dual = 0, n = s.size(), cur = 0;
  int tot_zero = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') tot_zero++;
  }
  LL ret = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      zero++;
      cur = 0;
      continue;
    }
    cur++;
    if (i+1 == n || s[i+1] == '0') {
      dual += cur/2;
      if (cur % 2 == 0) continue;
      int tot = zero + 1;
      if (i % 2 == 0) tot++;
      ret += tot / 2;
      ret += tot_zero - zero;
    }
  }
  ret += (LL)dual * (tot_zero+1);
  cur = n - tot_zero - 1;
  while (cur > 0) {
    ret += (cur+1)/2;
    cur--;
  }
  cout << ret << '\n';







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
