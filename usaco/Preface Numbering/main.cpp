/*
ID: txingml
PROG: preface
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
string s = "IVXLCDM";
int nums[] = {1, 5, 10, 50, 100, 500, 1000};
map<int, int> table;
int ret[7];

void solve(int num) {
  int base = 1;
  while (num) {
    int rem = num % 10;
    num /= 10;
    if (rem <= 3) {
      ret[table[base]] += rem;
    } else if (rem == 4) {
      ret[table[5*base]]++;
      ret[table[base]]++;
    } else if (rem <= 8) {
      ret[table[5*base]]++;
      ret[table[base]] += rem - 5;
    } else {
      ret[table[10*base]]++;
      ret[table[base]]++;
    }
    base = base * 10;
  }
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
  freopen("preface.in", "r", stdin);
  freopen("preface.out", "w", stdout);
  for (int i = 0; i < 7; i++) {
    table[nums[i]] = i;
  }
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    solve(i);
  }
  int tot = 0;
  for (int i = 0; i < 7; i++) {
    if (ret[i]) tot = i;
  }
  for (int i = 0; i <= tot; i++) {
    cout << s[i] << ' ' << ret[i] << '\n';
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
