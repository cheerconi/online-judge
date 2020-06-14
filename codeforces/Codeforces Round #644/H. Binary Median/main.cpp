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
  int t; cin >> t;
  while(t--) {
    LL n, m; cin >> n >> m;
    set<LL> table;
    LL a = (1LL<<(m-1));
    LL b = a, cur = a-1;
    for (int i = 0; i < n; i++) {
      string s; cin >> s;
      LL val = 0;
      for (int j = 0; j < m; j++) {
        if (s[j] == '0') continue;
        val += 1LL<<(m-j-1);
      }
      table.insert(val);
      if (val == cur) {
       if (a == b) {
         while (table.find(cur) != table.end()) cur++;
         b--;
       }  else {
         while (table.find(cur) != table.end()) cur--;
         a--;
       }
       continue;
      }
      if (val > cur) b--;
      else a--;
      int diff = 1;
      if (a > b) diff = -1;
      while (a != b && a != b+1) {
        cur += diff;
        while (table.find(cur) != table.end()) cur += diff;
        if (diff == 1) {
          b--;
          a++;
        } else {
          a--;
          b++;
        }
      }
    }
    string ret;
    for (int i = m-1; i >= 0; i--) {
      if (cur & (1LL<<i)) ret.push_back('1');
      else ret.push_back('0');
    }
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
