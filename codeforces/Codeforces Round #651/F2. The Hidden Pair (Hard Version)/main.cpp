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
const int MAXN = 1234;
vi nums;
vi edges[MAXN];
int node, dist, par[MAXN], deep[MAXN];
bool valid[MAXN];

void ask() {
  assert(!nums.empty());
  cout << "? " << nums.size();
  for (int num : nums) {
    cout << ' ' << num;
  }
  cout << endl;
  cin >> node >> dist;
  assert(node != -1);
}

void dfs(int cur) {
  valid[cur] = true;
  for (int nxt : edges[cur]) {
    if (nxt == par[cur]) continue;
    deep[nxt] = deep[cur] + 1;
    par[nxt] = cur;
    dfs(nxt);
  }
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
//  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    nums.clear();
    for (int i = 1; i <= n; i++) {
      edges[i].clear();
      nums.push_back(i);
    }
    for (int i = 0; i < n-1; i++) {
      int a, b; cin >> a >> b;
      edges[a].push_back(b);
      edges[b].push_back(a);
    }
    ask();
    int root = node, d = dist;
    deep[root] = 0;
    par[root] = 0;
    dfs(root);
    int a = n, b = 0;
    for (int i = 1; i <= n; i++) {
      if (deep[i] < d/2) continue;
      if (deep[i] > d) continue;
      b = max(b, deep[i]);
      a = min(a, deep[i]);
    }
    while (a < b) {
      int mid = (a+b+1) >> 1;
      nums.clear();
      for (int i = 1; i <= n; i++) {
        if (deep[i] == mid && valid[i]) nums.push_back(i);
      }
      if (nums.empty()) {
        b = mid-1;
        continue;
      }
      ask();
      if (d == dist) {
        memset(valid, false, sizeof(valid));
        dfs(node);
        a = mid;
      } else {
        b = mid-1;
      }
    }
    nums.clear();
    for (int i = 1; i <= n; i++) {
      if (deep[i] == a && valid[i]) nums.push_back(i);
    }
    int ret = -1;
    if (nums.size() == 1) {
      ret = nums[0];
    } else {
      ask();
      ret = node;
    }

    par[ret] = 0;
    deep[ret] = 0;
    dfs(ret);
    nums.clear();
    for (int i = 1; i <= n; i++) {
      if (deep[i] == d) nums.push_back(i);
    }
    ask();
    cout << "! " << ret << ' ' << node << endl;
    string s; cin >> s;
    assert(s == "Correct");






  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
