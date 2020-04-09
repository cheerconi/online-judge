/*
ID: txingml
PROG: palsquare
LANG: C++
*/
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
string solve(int i, int b) {
  string s;
  while (i) {
    int val = i % b;
    char c = val + '0';
    if (val >= 10) c = 'A' + val - 10;
    s.push_back(c);
    i /= b;
  }
  reverse(s.begin(), s.end());
  return s;

}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
  freopen("palsquare.in", "r", stdin);
  freopen("palsquare.out", "w", stdout);
  int b; cin >> b;
  for (int i = 1; i <= 300; i++) {
    int j = i*i;
    string s = solve(j, b);
    bool flag = true;
    int n = s.size();
    for (int k = 0; k < n/2; k++) {
      if (s[k] != s[n-1-k]) {
        flag = false;
        break;
      }
    }
    if (flag) cout << solve(i, b) << ' ' << s << '\n';

  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
