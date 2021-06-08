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
vector<pii> items;
vector<int> nums;

void dfs(int i, int cur, int s, int state) {
  if (i == items.size()) {
    assert(cur > 1);
    if (cur != nums.front() && state != 3) nums.push_back(cur);
    return;
  }
  int coeff = 1;
  if (s == 1) coeff = items[i].first;
  for (int j = s; j <= items[i].second; j++) {
    int nxt_state = -1;
    if (state == 1 && j == 1) {
      nxt_state = 2;
    } else if (state == 2 && j == 1) {
      nxt_state = 3;
    } else if (state == 3 && j == 0) {
      nxt_state = 3;
    }
    dfs(i+1, cur * coeff, 0, nxt_state);
    coeff *= items[i].first;
  }
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
    items.clear();
    nums.clear();
    LL val; cin >> val;
    nums.push_back(val);
    for (LL i = 2; i * i <= val; i++) {
      if (val % i != 0) continue;
      items.emplace_back(i, 0);
      while (val % i == 0) {
        items.back().second++;
        val /= i;
      }
    }
    if (val != 1) {
      items.emplace_back(val, 1);
    }
    for (int i = 0; i < items.size(); i++) {
      dfs(i, 1, 1, 1);
      if (i+1 < items.size()) {
        int tmp = items[i].first * items[i+1].first;
        if (tmp != nums.front()) nums.push_back(tmp);
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      cout << nums[i];
      if (i+1 == nums.size()) cout << '\n';
      else cout << ' ';
    }
    if (items.size() == 2 && items[0].second == 1 && items[1].second == 1) {
      cout << "1\n";
    } else {
      cout << "0\n";
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
