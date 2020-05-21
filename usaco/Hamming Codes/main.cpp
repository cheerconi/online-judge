/*
ID: txingml
PROG: hamming
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
bool check(const vi& vs, int val, int d) {
  for (int num : vs) {
    int tmp = num ^ val;
    if (__builtin_popcount(tmp) < d) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
  freopen("hamming.in", "r", stdin);
  freopen("hamming.out", "w", stdout);
  int n, b, d; cin >> n >> b >> d;
  int mask = 1<<b;
  vi ret;
  for (int i = 0; i < mask && ret.size() < n; i++) {
    if (check(ret, i, d)) ret.push_back(i);
  }
  assert(ret.size() == n);
  for (int i = 0; i < ret.size(); i++) {
    cout << ret[i];
    if (i+1 == ret.size() || i % 10 == 9) {
      cout << '\n';
    } else {
      cout << ' ';
    }
  }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
