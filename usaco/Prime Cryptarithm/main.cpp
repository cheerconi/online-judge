/*
ID: txingml
PROG: crypt1
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
bool used[10];
bool check(int val) {
  while (val) {
    if (!used[val%10]) return false;
    val /= 10;
  }
  return true;
}

bool check(int val, int len) {
  if (len == 3) return val >= 100 && val <= 999;
  assert(len == 4);
  return val >= 1000 && val <= 9999;
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
  freopen("crypt1.in", "r", stdin);
  freopen("crypt1.out", "w", stdout);
  int n, val; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> val;
    used[val] = true;
  }
  int ret = 0;
  for (int i = 100; i <= 999; i++) {
    if (!check(i)) continue;
    for (int j = 1; j <= 9; j++) {
      if (!check(j)) continue;
      int tmp = i*j;
      if (!check(tmp) || !check(tmp, 3)) continue;
      for (int k = 0; k <= 9; k++) {
        if (!check(k)) continue;
        int tmp2 = k * i;
        if (!check(tmp2) || !check(tmp2, 3)) continue;
        int tmp3 = tmp2 + tmp * 10;
        if (!check(tmp3) || !check(tmp3, 4)) continue;
        ret++;
      }
    }
  }
  cout << ret << endl;






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
