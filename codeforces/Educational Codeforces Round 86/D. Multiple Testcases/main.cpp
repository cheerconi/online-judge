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
const int MAXN = 2e5 + 10;
int nums[MAXN], c[MAXN];
vector<int> ret[MAXN];




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, k; cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  sort(nums, nums+n, greater<int>());
  for (int i = 1; i <= k; i++) {
    cin >> c[i];
  }
  set<pii> table;
  int j = k;
  for (int i = 0; i < n; i++) {
    while (j > nums[i]) j--;
    assert(j > 0);
    auto it = table.begin();
    if (it == table.end() || it->first == c[j]) {
      int id = table.size();
      table.emplace(1, id);
      ret[id].push_back(nums[i]);
      continue;
    }
    pii tmp{it->first+1, it->second};
    table.erase(it);
    table.insert(tmp);
    ret[tmp.second].push_back(nums[i]);
  }
  cout << table.size() << endl;
  for (int i = 0; i < table.size(); i++) {
    cout << ret[i].size();
    for (int num : ret[i]) {
      cout << ' ' << num;
    }
    cout << '\n';
  }








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
