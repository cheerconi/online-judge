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
int ps[2];

int query(int i) {
  cout << i+1 << endl;
  int ret;
  cin >> ret;
  return ret;
}

void do2(int i, int B, string& s) {
  s[i] = query(i) + '0';
  s[B-i-1] = query(B-i-1) + '0';
  ps[s[i] == s[B-i-1]] = i;
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
//  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int T, B; cin >> T >> B;
  for (int cs = 1; cs <= T; cs++) {
    string s(B, '?');
    int i = 0;
    ps[0] = -1; ps[1] = -1;
    for (int cnt = 1; cnt <= 150; cnt += 2) {
      if (i >= B/2) break;
      if (cnt % 10 == 1) {
        int done = 0;
        if (ps[1] != -1) {
          done++;
          int tmp = query(ps[1]);
          if (tmp+'0' != s[ps[1]]) {
            for (char& c : s) {
              if (c == '?') continue;
              c = 1 - c + '0' + '0';
            }
          }
        }
        if (ps[0] != -1) {
          done++;
          int tmp = query(ps[0]);
          if (tmp+'0' != s[ps[0]]) {
            reverse(s.begin(), s.end());
          }
        }
        if (done == 1) {
          query(0);
        } else if (done == 0) {
          do2(i, B, s);
          i++;
        }
      } else {
        do2(i, B, s);
        i++;
      }
    }
    cout << s << endl;
    char ret;
    cin >> ret;
    assert(ret == 'Y');

  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
