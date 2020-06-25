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
const int MAXN = 233;
int ret[MAXN];

bool try_to_process(int fi, int n, const vector<set<int>>& const_nums, const vi& const_cnt) {
  auto nums = const_nums;
  auto cnt = const_cnt;
  for (int i = n-1; i >= 2; i--) {
    vector<int> ones;
    for (int j = 1; j <= n; j++) {
      if (cnt[j] == 1 && j != fi) ones.push_back(j);
    }
    if (ones.size() != 1) {
      if (ones.size() != 2) return false;
      if (fi != -1) return false;
      if(try_to_process(ones[0], n, const_nums, const_cnt)) return true;
      return try_to_process(ones[1], n, const_nums, const_cnt);
    }
    int cur = ones[0];
    ret[i] = cur;
    for (set<int>& table : nums) {
      if (table.find(cur) != table.end()) {
        for (int num : table) {
          cnt[num]--;
        }
        table.clear();
        break;
      }
    }
  }
  vector<int> ones;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 1) ones.push_back(i);
    else {
      if (cnt[i] != 0) return false;
    }
  }
  if (ones.size() != 2) return false;
  if (fi != -1) {
    if (ones[0] != fi && ones[1] != fi) return false;
  }
  ret[0] = ones[0];
  ret[1] = ones[1];
  if (fi != -1 && ret[0] != fi) {
    swap(ret[0], ret[1]);
  }
  for (const auto& table : const_nums) {
    if (table.find(ret[0]) != table.end() && table.find(ret[1]) == table.end()) {
      if (fi != -1 && ret[0] == fi) return false;
      swap(ret[0], ret[1]);
      fi = ret[0];
    }
  }
  map<int, int> value_to_idx;
  for (int i = 0; i < n; i++) {
    value_to_idx[ret[i]] = i;
  }
  for (const auto& table : const_nums) {
    vector<int> idx;
    for (int num : table) {
      idx.push_back(value_to_idx[num]);
    }
    sort(idx.begin(), idx.end());
    if (idx.back() - idx.front() + 1 != idx.size()) return false;
  }
  return true;
}


void solve(const vector<set<int>>& nums, const vi& cnt) {
  int n = nums.size() + 1;
  vector<int> ones;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 1) ones.push_back(i);
  }
  assert(!ones.empty());
  assert(ones.size() <= 2);
  if (ones.size() == 1) {
    assert(try_to_process(-1, n, nums, cnt));
    return;
  }
  if (!try_to_process(ones[0], n, nums, cnt)) {
    assert(try_to_process(ones[1], n, nums, cnt));
  }
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<set<int>> nums(n-1);
    vector<int> cnt(n+1);
    for (int i = 0; i < n-1; i++) {
      int m; cin >> m;
      while (m--) {
        int val; cin >> val;
        nums[i].insert(val);
        cnt[val]++;
      }
    }
    solve(nums, cnt);
    for (int i = 0; i < n; i++) {
      cout << ret[i];
      if (i+1 == n) cout << '\n';
      else cout << ' ';
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
