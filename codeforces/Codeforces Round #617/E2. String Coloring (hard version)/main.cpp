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





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  string s; cin >> s;
  vector<pci> items(n);
  for (int i = 0; i < n; i++) {
    items[i].first = s[i];
    items[i].second = i;
  }
  sort(items.begin(), items.end());
  vector<int> ret(n);
  map<int, int> table;
  table[n-1] = 1;
  for (const auto& item : items) {
    auto it = table.lower_bound(item.second);
    ret[item.second] = it->second;
    auto it2 = it;
    while (it2 != table.begin()) {
      it2--;
      if (it2->second > it->second+1) break;
      it2 = table.erase(it2);
    }
    if (it->first == item.second) it->second++;
    else table[item.second] = it->second+1;
  }
  int ma = 1;
  for (int i = 0; i < n; i++) {
    ma = max(ma, ret[i]);
  }
  cout << ma << '\n';
  for (int i = 0; i < n; i++) {
    cout << ret[i];
    if (i+1 == n) cout << '\n';
    else cout << ' ';
  }








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
