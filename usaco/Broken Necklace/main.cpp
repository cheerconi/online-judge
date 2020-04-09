/*
ID: txingml
PROG: beads
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
typedef pair<char, int> pci;
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

int solve(const string& s) {
  vector<pci> data;
  for (char c : s) {
    if (data.empty() || data.back().first != c) {
      data.emplace_back(c, 1);
    } else {
      data.back().second++;
    }
  }
  if (data.size() <= 2) return s.size();
  vector<pci> tmp;
  for (int i = 0; i < data.size(); i++) {
    if (tmp.empty() || data[i].first != 'w' || i+1 >= data.size() || data[i+1].first != tmp.back().first) {
      tmp.push_back(data[i]);
    } else {
      tmp.back().second += data[i+1].second + data[i].second;
      i++;
    }
  }
  if (tmp.size() <= 2) return s.size();
  if (tmp.back().first == tmp[0].first) {
    tmp[0].second += tmp.back().second;
    tmp.pop_back();
  }
  if (tmp.size() <= 2) return s.size();
  if (tmp[0].first == 'w' && tmp[1].first == tmp.back().first) {
    tmp[1].second += tmp[0].second + tmp.back().second;
    tmp.pop_back();
    tmp.erase(tmp.begin());
  }
  if (tmp.size() <= 2) return s.size();
  if (tmp.back().first == 'w' && tmp[0].first == tmp[tmp.size()-2].first) {
    tmp[0].second += tmp.back().second + tmp[tmp.size()-2].second;
    tmp.pop_back();
    tmp.pop_back();
  }
  if (tmp.size() <= 3) return s.size();
  int ret = 0;
  int n = tmp.size();
  for (int i = 0; i < tmp.size(); i++) {
    if (tmp[i].first == 'w') continue;
    int a = tmp[i].second, cnt = 1, j = (i+1) % n;
    if (tmp[(i-1+n) % n].first == 'w') {
      cnt++;
      a += tmp[(i-1+n)%n].second;
    }
    if (tmp[j].first == 'w') {
      cnt++;
      a += tmp[j].second;
      j = (j+1) % n;
    }
    a += tmp[j].second;
    cnt++;
    j = (j+1) % n;
    if (n > cnt && tmp[j].first == 'w') a += tmp[j].second;
    ret = max(ret, a);
  }
  return ret;
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
  freopen("beads.in", "r", stdin);
  freopen("beads.out", "w", stdout);
  int n; cin >> n;
  string s; cin >> s;
  cout << solve(s) << '\n';









/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
