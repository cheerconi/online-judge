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
#define leftnode (node<<1)
#define rightnode ((node<<1)|1)
#define getmid ((left+right)>>1)

const int MAXN = 1e5 + 10;
int nums[MAXN], level[MAXN];
vi level_to_idx[MAXN];
set<pii> level_to_item[MAXN];
int dp[MAXN<<2];

void update(int node, int left, int right, int i, int value) {
  if (left == right) {
    dp[node] = value;
    return;
  }
  int mid = getmid;
  if (i <= mid) update(leftnode, left, mid, i, value);
  else update(rightnode, mid+1, right, i, value);
  dp[node] = max(dp[leftnode], dp[rightnode]);
}

int query(int node, int left, int right, int i, int j) {
  if (i > j) return 0;
  if (right < i || j < left) return -1;
  if (i <= left && right <= j) return dp[node];
  int mid = getmid;
  int ret1 = query(leftnode, left, mid, i, j);
  int ret2 = query(rightnode, mid+1, right, i, j);
  return max(ret1, ret2);
}


int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int m = 1e5;
  int ret = 0;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    int val = query(1, 1, m,1,nums[i]-1) + 1;
    update(1, 1, m, nums[i], val);
    level[i] = val;
    level_to_idx[val].push_back(i);
    level_to_item[val].emplace(nums[i], i);
    ret = max(ret, val);
  }
  string s(n, '1');

  set<int> cur;
  for (int i = 0; i < n; i++) {
    if (level[i] == ret) cur.insert(i);
  }
  for (int lv = ret; lv >= 1; lv--) {
    assert(!cur.empty());
    char c = cur.size() == 1 ? '3' : '2';
    set<int> nxt;
    for (auto it = cur.rbegin(); it != cur.rend(); it++) {
      int p = *it;
      s[p] = c;
      while (!level_to_idx[lv-1].empty() && level_to_idx[lv-1].back() > p) {
        int idx = level_to_idx[lv-1].back();
        auto k = make_pair(nums[idx], idx);
        auto it_k = level_to_item[lv-1].find(k);
        if (it_k != level_to_item[lv-1].end()) level_to_item[lv-1].erase(it_k);
        level_to_idx[lv-1].pop_back();
      }
      while (!level_to_item[lv-1].empty()) {
        int tmp = level_to_item[lv-1].begin()->first;
        if (tmp >= nums[p]) break;
        nxt.insert(level_to_item[lv-1].begin()->second);
        level_to_item[lv-1].erase(level_to_item[lv-1].begin());
      }
    }
    cur = move(nxt);
  }
  cout << s << endl;










/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
