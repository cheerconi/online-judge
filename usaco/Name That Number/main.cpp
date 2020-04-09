/*
ID: txingml
PROG: namenum
LANG: C++
*/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <ctime>
#include <deque>
#include <fstream>
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
map<int, string> table{{2, "ABC"}, {5, "JKL"}, {8, "TUV"}, {3, "DEF"}, {6, "MNO"}, {9, "WXY"}, {4, "GHI"}, {7, "PRS"}};
set<string> dict;
string s;
vector<string> ret;
void solve(int i, string& cur) {
  if (i == s.size()) {
    if (dict.find(cur) != dict.end()) {
      ret.push_back(cur);
    }
    return;
  }
  auto it = table.find(s[i]-'0');
  if (it == table.end()) return;
  for (char c : it->second) {
    cur.push_back(c);
    solve(i+1, cur);
    cur.pop_back();
  }
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
  freopen("namenum.in", "r", stdin);
  freopen("namenum.out", "w", stdout);

  ifstream infile("dict.txt");
  while(getline(infile, s)) {
    dict.insert(s);
  }
  cin >> s;
  string cur;
  solve(0, cur);
  sort(ret.begin(), ret.end());
  if (ret.empty()) cout << "NONE\n";
  for (const auto& name : ret) {
    cout << name << '\n';
  }









/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
