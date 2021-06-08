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

string solve(const string& s) {
  int n = s.size();
  vector<vi> idx(26);
  vector<string> ret(26);
  for (int i = 0; i < 26; i++) {
    ret[i].push_back(i+'a');
  }
  for (int i = 0; i < n; i++) {
    idx[s[i]-'a'].push_back(i);
  }
  while (true) {
    for (int i = 0; i < idx.size(); i++) {
      if (idx[i].empty()) {
        return ret[i];
      }
    }
    vector<vi> n_idx(idx.size() * 26);
    vector<string> n_ret(idx.size() * 26);
    for (int i = 0; i < ret.size(); i++) {
      for (int j = 0; j < 26; j++) {
        n_ret[i*26+j] = ret[i];
        n_ret[i*26+j].push_back('a' + j);
      }
    }
    int sz = ret[0].size();
    for (int i = 0; i < idx.size(); i++) {
      for (int j : idx[i]) {
        if (j+sz < n) {
          int k = s[j+sz] - 'a';
          n_idx[i*26+k].push_back(j);
        }
      }
    }
    idx = move(n_idx);
    ret = move(n_ret);
  }
  assert(false);
  return "";
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
    int n; cin >> n;
    string s; cin >> s;
    cout << solve(s) << '\n';

  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
