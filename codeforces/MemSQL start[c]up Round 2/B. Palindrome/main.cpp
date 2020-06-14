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
const int MAXN = 2600 + 10;
int cnt[26];
struct Item{
  int val, a, b;
  bool flag = false;

};
Item dp[MAXN][MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  string s; cin >> s;
  for (char c : s) {
    cnt[c-'a']++;
    if (cnt[c-'a'] == 100) {
      cout << string(100, c) << '\n';
      return 0;
    }
  }
  int n = s.size();
  for (int len = 1; len <= n; len++) {
    for (int i = 0; i+len-1 < n; i++) {
      int j = i+len-1;
      int delta = 0;
      if (i == j) delta = 1;
      else if (s[i] == s[j]) delta = 2;
      dp[i][j].flag = s[i] == s[j];
      if (i+1 <= j-1) {
        dp[i][j].val = delta + dp[i+1][j-1].val;
        if (dp[i+1][j-1].flag) {
          dp[i][j].a = i+1;
          dp[i][j].b = j-1;
        } else {
          dp[i][j].a = dp[i+1][j-1].a;
          dp[i][j].b = dp[i+1][j-1].b;
        }
      } else {
        dp[i][j].val = delta;
        dp[i][j].a = -1;
        dp[i][j].b = -1;
      }
      if (i+1 <= j && dp[i+1][j].val > dp[i][j].val) {
        dp[i][j].flag = false;
        dp[i][j].val = dp[i+1][j].val;
        if (dp[i+1][j].flag) {
          dp[i][j].a = i+1;
          dp[i][j].b = j;
        } else {
          dp[i][j].a = dp[i+1][j].a;
          dp[i][j].b = dp[i+1][j].b;
        }
      }
      if (i <= j-1 && dp[i][j-1].val > dp[i][j].val) {
        dp[i][j].flag = false;
        dp[i][j].val = dp[i][j-1].val;
        if (dp[i][j-1].flag) {
          dp[i][j].a = i;
          dp[i][j].b = j-1;
        } else {
          dp[i][j].a = dp[i][j-1].a;
          dp[i][j].b = dp[i][j-1].b;
        }
      }
    }
  }
  string ret;
  int a = 0, b = n-1;
  int idx = -1;
  while (ret.size() < 50) {
    if (a == -1) break;
    if (a == b) {
      idx = a;
      break;
    }
    if (dp[a][b].flag) {
      ret.push_back(s[a]);
    }
    int tmp_a = dp[a][b].a;
    int tmp_b = dp[a][b].b;
    a = tmp_a;
    b = tmp_b;
  }
  string tmp = ret;
  reverse(tmp.begin(), tmp.end());
  if (idx != -1) ret.push_back(s[idx]);
  ret += tmp;
  cout << ret << '\n';







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
