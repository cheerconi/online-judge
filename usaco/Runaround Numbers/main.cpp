/*
ID: txingml
PROG: runround
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
int out[12], in[12], digit[12];
string s;

bool dfs(int i, bool bound) {
  if (i == s.size()) {
    vector<bool> used(s.size());
    int cur = 0, cnt = 1;
    used[cur] = true;
    while (true) {
      if (out[cur] == 0) return false;
      cur = (out[cur] + cur) % s.size();
      if (used[cur]) break;
      used[cur] = true;
      cnt++;
    }
    return cnt == s.size();
  }
  assert(out[i] == 0);
  int j = 1;
  if (bound) j = s[i]-'0';
  for (; j <= 9; j++) {
    if (digit[j]) continue;
    int nxt = (i+j) % s.size();
    if (in[nxt] == 0) {
      out[i] = j;
      in[nxt] = 1;
      digit[j] = 1;
      if (dfs(i+1, bound && j == s[i]-'0')) return true;
      out[i] = 0;
      in[nxt] = 0;
      digit[j] = 0;
    }
  }
  return false;

}
LL solve() {
  int n = s.size();
  if (n == 1) {
    return s[0] - '0';
  }
  assert(dfs(0, true));
  LL ret = 0;
  for (int i = 0; i < n; i++) {
    ret = ret * 10 + out[i];
  }
  return ret;
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
  freopen("runround.in", "r", stdin);
  freopen("runround.out", "w", stdout);
  LL num; cin >> num;
  num++;
  s = to_string(num);
  cout << solve() << '\n';








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
