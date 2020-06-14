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
//  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif

  while (true) {
    string s;
    cin >> s;
    if (s != "start") break;
    LL a = 1;
    while (true) {
      cout << "? " << a << ' ' << a*2 << endl;
      cin >> s;
      if (s == "x") break;
      a <<= 1;
    }
    if (a == 1) {
      cout << "? 2 1" << endl;
      cin >> s;
      if (s == "x") cout << "! 1" << endl;
      else cout << "! 2" << endl;
      continue;
    }
    LL x = a+1, y = a<<1;
    while (x < y) {
      LL mid = (x+y) >> 1;
      if (a == mid) {
        cout << "? " << a << ' ' << a+1 << endl;
        cin >> s;
      }
      cout << "? " << a << ' ' << mid << endl;
      cin >> s;
      if (s == "x") y = mid;
      else x = mid + 1;
    }
    cout << "! " << x << endl;
  }








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
