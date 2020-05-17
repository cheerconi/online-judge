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
const int M = 400000 + 10;
int fact[M];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  for (int i = 2; i < M; i++) {
    if (fact[i] == 0) {
      for (int j = i+i; j < M; j += i) {
        if (fact[j] == 0) fact[j] = i;
      }
    }
  }
  int n, val; cin >> n;
  map<int, vi> table;
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> val;
    map<int, int> cur;
    while (fact[val] > 0) {
      cur[fact[val]]++;
      val /= fact[val];
    }
    if (val > 1) cur[val]++;
    for (const auto& item : cur) {
      cnt[item.first]++;
      table[item.first].push_back(item.second);
      auto it = table.find(item.first);
      if (it->second.size() == 3) {
        sort(it->second.begin(), it->second.end());
        it->second.pop_back();
      }
    }
  }
  LL ret = 1;
  for (const auto& item : cnt) {
    if (item.second <= n-2) continue;
    auto it = table.find(item.first);
    sort(it->second.begin(), it->second.end());
    int tmp;
    if (item.second == n-1) {
      tmp = it->second.front();
    } else {
      assert(item.second == n);
      tmp = it->second.back();
    }
    while (tmp > 0) {
      ret = ret * item.first;
      tmp--;
    }
  }
  cout << ret << endl;








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
