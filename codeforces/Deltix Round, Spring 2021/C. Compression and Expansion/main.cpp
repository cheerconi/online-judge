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
const int MAXN = 1234;

vector<vi> solve(int n) {
  vector<vi> ret(n);
  vector<vi> idx(n+1);
  int val; cin >> val;
  assert(val == 1);
  ret[0].push_back(1);
  idx[1].push_back(0);
  for (int i = 1; i < n; i++) {
    cin >> val;
    if (val == 1) {
      ret[i] = ret[i-1];
      idx[1].push_back(ret[i].size());
      ret[i].push_back(1);
      continue;
    }
    assert(!idx[val-1].empty());
    int k = idx[val-1].back();
    vector<vi> tmp(n+1);
    for (int j = 0; j < k; j++) {
      ret[i].push_back(ret[i-1][j]);
      tmp[ret[i-1][j]].push_back(j);
    }
    tmp[val].push_back(ret[i].size());
    ret[i].push_back(val);
    idx = move(tmp);
  }
  return ret;
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    vector<vi> ret = solve(n);
    for (int i = 0; i < n; i++) {
      assert(!ret[i].empty());
      cout << ret[i][0];
      for (int j = 1; j < ret[i].size(); j++) {
        cout << '.' << ret[i][j];
      }
      cout << '\n';
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
