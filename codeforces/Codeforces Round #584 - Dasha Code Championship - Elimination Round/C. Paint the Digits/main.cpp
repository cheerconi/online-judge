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
deque<int> pos[12];
set<int> ret[2];
string solve() {
  int n; cin >> n;
  string s; cin >> s;
  for (int i = 0; i < 10; i++) {
    pos[i].clear();
  }
  for (int i = 0; i < n; i++) {
    pos[s[i]-'0'].push_back(i);
  }
  string tmp = s;
  sort(tmp.begin(), tmp.end());
  ret[0].clear();
  ret[1].clear();
  int ma = -1, mi = 11;
  for (int i = 0; i < n; i++) {
    if (s[i] < tmp[i]) {
      ret[0].insert(pos[s[i] - '0'].back());
      pos[s[i] - '0'].pop_back();
      ma = max(ma, s[i]-'0');
    } else if (s[i] > tmp[i]){
      ret[1].insert(pos[s[i]-'0'].front());
      pos[s[i]-'0'].pop_front();
      mi = min(mi, s[i]-'0');
    }
  }
  if (ma > mi) return "-";
  for (char& c : tmp) {
    c = '0';
  }
  for (int p : ret[0]) {
    tmp[p] = '1';
  }
  for (int p : ret[1]) {
    tmp[p] = '2';
  }
  for (int i = 0; i < n; i++) {
    if (tmp[i] != '0') continue;
    if (s[i]-'0' < ma) {
      tmp[i] = '1';
      ret[0].insert(i);

    } else if (s[i]-'0' > mi) {
      tmp[i] = '2';
      ret[1].insert(i);
    }
  }
  for (int i = 0; i < n; i++) {
    if (tmp[i] != '0') continue;
    auto it = ret[0].lower_bound(i);
    if (it == ret[0].end() || s[*it] >= s[i]) {
      tmp[i] = '1';
      ret[0].insert(i);
    } else {
      tmp[i] = '2';
      ret[1].insert(i);
    }
  }
  int cur = -1;
  for (int p : ret[0]) {
    if (cur > s[p]-'0') return "-";
    cur = s[p] - '0';
  }
  for (int p : ret[1]) {
    if (cur > s[p]-'0') return "-";
    cur = s[p] - '0';
  }
  return tmp;
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  while (n--) {
    cout << solve() << endl;
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
