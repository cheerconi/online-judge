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
struct Table{
  set<pii> data;
  LL cnt = 0;
  LL magic = 0;
  void insert(int val, int t) {
    data.emplace(val, t);
    cnt += val;
    if (t == 1) magic++;
  }
  bool erase(int val, int t) {
    auto it = data.find({val, t});
    if (it == data.end()) return false;
    data.erase(it);
    cnt -= val;
    if (t == 1) magic--;
    return true;
  }
};
Table table[2];

LL solve() {
  int tot = table[0].magic + table[1].magic;
  while (table[1].data.size() < tot) {
    assert (!table[0].data.empty());
    auto item = *table[0].data.rbegin();
    table[0].erase(item.first, item.second);
    table[1].insert(item.first, item.second);
  }
  while (table[1].data.size() > tot) {
    auto item = *table[1].data.begin();
    table[1].erase(item.first, item.second);
    table[0].insert(item.first, item.second);
  }
  LL ret = table[1].cnt * 2 + table[0].cnt;;
  if (tot > 0 && table[1].data.size() == table[1].magic) {
    ret -= table[1].data.begin()->first;
    if(!table[0].data.empty()) ret += table[0].data.rbegin()->first;
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
  int n; cin >> n;
  while (n--) {
    int t, val; cin >> t >> val;
    if (val > 0) {
      if (table[1].data.empty()) {
        table[0].insert(val, t);
      } else if (table[1].data.begin()->first <= val) {
        table[1].insert(val, t);
      } else {
        table[0].insert(val, t);
      }
    } else {
      if (!table[0].erase(-val, t)) {
        assert (table[1].erase(-val, t));
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
