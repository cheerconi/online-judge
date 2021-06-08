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
const int MAXN = 123;
string s[MAXN];

string add_one(string& x) {
  int tmp = 1;
  reverse(x.begin(), x.end());
  string ret;
  for (char c : x) {
    int val = tmp + (c-'0');
    ret.push_back(val % 10 + '0');
    tmp = val / 10;
  }
  assert(tmp == 0);
  reverse(ret.begin(), ret.end());
  return ret;

}

int solve(int i, int j) {
  if (s[i].size() < s[j].size()) return 0;
  if (s[i].size() == s[j].size()) {
    if (s[i] < s[j]) return 0;
    s[j].push_back('0');
    return 1;
  }
  int n = s[j].size();
  string tmp = s[i].substr(0, n);
  if (tmp > s[j]) {
    int cnt = 0;
    while (s[j].size() <= s[i].size()) {
      cnt++;
      s[j].push_back('0');
    }
    return cnt;
  }
  if (tmp < s[j]) {
    int cnt = 0;
    while (s[j].size() < s[i].size()) {
      cnt++;
      s[j].push_back('0');
    }
    return cnt;
  }
  int m = s[i].size();
  string res = s[i].substr(n, m-n);
  if (res == string(m-n, '9')) {
    int cnt = 0;
    while (s[j].size() <= s[i].size()) {
      cnt++;
      s[j].push_back('0');
    }
    return cnt;
  }
  LL val = stoll(res);
  int ret = res.size();
  val++;
  res = to_string(val);
  for (int k = 0; k < ret - res.size(); k++) {
    s[j].push_back('0');
  }
  s[j] += res;
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
  for (int cs = 1; cs <= T; cs++) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    int ret = 0;
    for (int i = 0; i+1 < n; i++) {
      ret += solve(i, i+1);
    }
    cout << "Case #" << cs << ": " << ret << endl;
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
