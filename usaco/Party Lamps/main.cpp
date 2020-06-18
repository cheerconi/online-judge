/*
ID: txingml
PROG: lamps
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
string s, cur;
vector<string> ret;

void dfs(int i, int cnt, int c) {
  if (cnt > c) return;
  if (i == 4) {
    if ((c - cnt) % 2 != 0) return;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '?') continue;
      if (s[j] != cur[j]) return;
    }
    ret.push_back(cur);
    return;
  }
  dfs(i+1, cnt, c);
  int delta, j;
  if (i == 0) {
    delta = 1;
    j = 0;
  } else if (i == 1) {
    delta = 2;
    j = 0;
  } else if (i == 2) {
    delta = 2;
    j = 1;
  } else {
    delta = 3;
    j = 0;
  }
  for (int k = j; k < cur.size(); k += delta) {
    cur[k] = 1 - (cur[k]- '0') + '0';
  }
  dfs(i+1, cnt+1, c);
  for (int k = j; k < cur.size(); k += delta) {
    cur[k] = 1 - (cur[k]- '0') + '0';
  }
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
  freopen("lamps.in", "r", stdin);
  freopen("lamps.out", "w", stdout);
  int n, c; cin >> n >> c;
  s = string(n, '?');
  cur = string(n, '1');
  int val;
  cin >> val;
  while (val != -1) {
    s[val-1] = '1';
    cin >> val;
  }
  cin >> val;
  while (val != -1) {
    s[val-1] = '0';
    cin >> val;
  }
  dfs(0, 0, c);
  if (ret.empty()) {
    cout << "IMPOSSIBLE\n";
  } else {
    sort(ret.begin(), ret.end());
    for (const string& tmp : ret) {
      cout << tmp << '\n';
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
