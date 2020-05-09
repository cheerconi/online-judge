/*
ID: txingml
PROG: pprime
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
int get(int i, bool odd) {
  int ret = i;
  if (odd) i /= 10;
  while (i) {
    ret = ret * 10 + i % 10;
    i /= 10;
  }
  return ret;
}

bool check(int val) {
  for (int i = 2; i*i <= val; i++) {
    if (val % i == 0) return false;
  }
  return true;
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
  freopen("pprime.in", "r", stdin);
  freopen("pprime.out", "w", stdout);
  int a, b; cin >> a >> b;
  vector<int> ret;
  for (int i = 1; ; i++) {
    int val = get(i, true);
    if (val < a) continue;
    if (val > b) break;
    if (check(val)) ret.push_back(val);
  }
  for (int i = 1; ; i++) {
    int val = get(i, false);
    if (val < a) continue;
    if (val > b) break;
    if (check(val)) ret.push_back(val);
  }
  sort(ret.begin(), ret.end());
  for(int num : ret) cout << num << '\n';





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
