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
const int MAXN = 1e5 + 10;
int x;
string s, ret;
vi edges[MAXN];

bool dfs(int i, char c) {
  if (ret[i-1] == c) return true;
  if (ret[i-1]  != '?') return false;
  ret[i-1] = c;
  if (c == '1') {
    edges[i].clear();
    return true;
  }
  for (int nxt : edges[i]) {
    if(!dfs(nxt, '1')) return false;
  }
  return true;
}


bool solve() {
  int n = s.size();
  for (int i = 1; i <= n; i++) {
    if (i > x && i+x <= n) {
      if (s[i-1] == '1') {
        if (ret[i+x-1] == '?' && ret[i-x-1] == '?') {
          edges[i+x].push_back(i-x);
          edges[i-x].push_back(i+x);
        } else if (ret[i+x-1] == '0' && ret[i-x-1] == '0') {
          return false;
        } else if (ret[i+x-1] == '0') {
          if (!dfs(i-x, '1')) return false;
        } else if (ret[i-x-1] == '0') {
          if (!dfs(i+x, '1')) return false;
        }
      } else {
        if (!dfs(i-x, '0')) return false;
        if (!dfs(i+x, '0')) return false;
      }

    } else if (i > x) {
      if (s[i-1] == '1') {
        if (!dfs(i-x, '1')) return false;
      } else {
        if (!dfs(i-x, '0')) return false;
      }
    } else if (i+x <= n) {
      if (s[i-1] == '1') {
        if (!dfs(i+x, '1')) return false;
      } else {
        if (!dfs(i+x, '0')) return false;
      }
    } else {
      if (s[i-1] == '1') return false;
    }
  }
  return true;
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while (t--) {
    cin >> s >> x;
    int n = s.size();
    for (int i = 1; i <= n; i++) {
      edges[i].clear();
    }
    ret = string(n, '?');
    if (solve()) {
      for (int i = 0; i < ret.size(); i++) {
        if (ret[i] == '?') ret[i] = '1';
      }
      cout << ret << '\n';
    } else {
      cout << "-1\n";
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
