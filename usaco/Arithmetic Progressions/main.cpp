/*
ID: txingml
PROG: ariprog
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
const int MAXN = 250 * 250 * 2 + 10;
bool used[MAXN];
map<int, int> table[MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
  freopen("ariprog.in", "r", stdin);
  freopen("ariprog.out", "w", stdout);
  int n, m; cin >> n >> m;
  set<int> nums;
  for (int i = 0; i <= m; i++) {
    for (int j = i; j <= m; j++) {
      nums.insert(i*i + j*j);
    }
  }
  for (int num : nums) {
    used[num] = true;
  }
  for (auto it1 = nums.begin(); it1 != nums.end(); it1++) {
    for (auto it2 = it1; it2 != nums.end(); it2++) {
      if (it1 == it2) continue;
      int diff = *it2 - *it1;
      if (diff * (n-1) + *it1 >= MAXN) break;
      int pre = *it1 - diff;
      if (pre >= 0 && used[pre]) {
        auto it = table[diff].find(pre);
        if (it != table[diff].end() && it->second-1 >= n) table[diff][*it1] = it->second - 1;
        continue;
      }
      int cnt = 2;
      int cur = *it2;
      while (cur+diff < MAXN && used[cur+diff]) {
        cnt++;
        cur += diff;
      }
      if (cnt >= n) table[diff][*it1] = cnt;
    }
  }
  vector<pii> ret;
  for (int diff = 0; diff < MAXN; diff++) {
    for (const auto& item : table[diff]) {
      ret.emplace_back(diff, item.first);
    }
  }
  if (ret.empty()) {
    cout << "NONE\n";
  } else {
    for (const auto& item : ret) {
      cout << item.second << ' ' << item.first << '\n';
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
