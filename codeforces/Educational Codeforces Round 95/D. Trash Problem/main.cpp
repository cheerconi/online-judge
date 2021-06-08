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
int nums[MAXN];
set<int> pos;
map<int, int> dist;

int solve() {
  if (pos.size() <= 2) return 0;
  int ret = *pos.rbegin() - *pos.begin();
  ret -= dist.rbegin()->first;
  return ret;
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, q; cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  sort(nums, nums+n);

  for (int i = 0; i < n; i++) {
    pos.insert(nums[i]);
    if (i-1 >= 0) dist[nums[i]-nums[i-1]]++;
  }
  cout << solve() << '\n';
  while (q--) {
    int cmd, val;
    cin >> cmd >> val;
    if (cmd == 0) {
      int d1 = 0, d2 = 0;
      auto it = pos.find(val);
      if (it != pos.begin()) {
        auto pre = it; pre--;
        d1 = *it - *pre;
        auto tmp = dist.find(d1);
        tmp->second--;
        if (tmp->second == 0) dist.erase(tmp);
      }
      auto nxt = it; nxt++;
      if (nxt != pos.end()) {
        d2 = *nxt - *it;
        auto tmp = dist.find(d2);
        tmp->second--;
        if (tmp->second == 0) dist.erase(tmp);
      }
      if (d1 > 0 && d2 > 0) {
        dist[d1+d2]++;
      }
      pos.erase(it);
    } else {
      int d1 = 0, d2 = 0;
      auto it = pos.insert(val).first;
      if (it != pos.begin()) {
        auto pre = it; pre--;
        d1 = *it - *pre;
        dist[d1]++;
      }
      auto nxt = it; nxt++;
      if (nxt != pos.end()) {
        d2 = *nxt - *it;
        dist[d2]++;
      }
      if (d1 > 0 && d2 > 0) {
        auto tmp = dist.find(d1+d2);
        tmp->second--;
        if (tmp->second == 0) dist.erase(tmp);
      }
    }
    cout << solve() << '\n';
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
