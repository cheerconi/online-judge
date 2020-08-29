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
int cnt[MAXN];

bool check(const set<pii>& table) {
  if (table.empty()) return false;
  auto it = table.rbegin();
  if (it->first < 4) return false;
  if (it->first >= 8) return true;
  int rem = 2;
  if (it->first >= 6) rem--;
  it++;
  while (it != table.rend() && rem > 0) {
    if (it->first >= 4) rem -= 2;
    else if (it->first >= 2) rem--;
    it++;
  }
  return rem <= 0;
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int val; cin >> val;
    cnt[val]++;
  }
  set<pii> table;
  for (int i = 1; i <= 1e5; i++) {
    if (cnt[i] >= 2) table.emplace(cnt[i], i);
  }
  int q; cin >> q;
  while (q--) {
    char c; cin >> c;
    int val; cin >> val;
    if (cnt[val] >= 2) table.erase({cnt[val], val});
    if (c == '-') cnt[val]--;
    else cnt[val]++;
    if (cnt[val] >= 2) table.emplace(cnt[val], val);
    if (check(table)) cout << "YES\n";
    else cout << "NO\n";
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
