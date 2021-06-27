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
const int MAXN = 550;
int dp[MAXN], from[MAXN];

LL ask(const vi& idx) {
  cout << "?";
  for (int id : idx) {
    cout << ' ' << id;
  }
  cout << endl;
  LL val; cin >> val;
  return val;

}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, k; cin >> n >> k;
  memset(dp, -1, sizeof(dp));
  memset(from, -1, sizeof(from));
  dp[n] = 0;
  queue<int> q;
  q.push(n);
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    int j = n - cur;
    for (int x = 0; x <= j; x++) {
      if (x > k) continue;
      int y = k - x;
      if (y > cur) continue;
      int z = cur + x - y;
      if (dp[z] != -1) continue;
      dp[z] = dp[cur]+1;
      from[z] = cur;
      q.push(z);
    }
  }
  if (dp[0] == -1) {
    cout << "-1" << endl;
    return 0;
  }
  vector<int> state;
  state.push_back(0);
  while (state.back() != n) {
    state.push_back(from[state.back()]);
  }
  LL ret = 0;
  vector<int> used, unused;
  for (int i = 1; i <= n; i++) {
    unused.push_back(i);
  }
  for (int i = (int)state.size()-2; i >= 0; i--) {
    assert(unused.size() == state[i+1]);
    vi idx;
    int diff = state[i+1] - state[i];
    assert((diff + k) % 2 == 0);
    int x= (diff + k) / 2;
    int y = k - x;
    for (int j = 0; j < x; j++) {
      idx.push_back(unused.back());
      unused.pop_back();
    }
    assert(y <= used.size());
    for (int j = 0; j < y; j++) {
      idx.push_back(used.back());
      used.pop_back();
    }
    assert(idx.size() == k);
    ret = ret ^ ask(idx);
    for (int j = 0; j < k; j++) {
      if (j < x) used.push_back(idx[j]);
      else unused.push_back(idx[j]);
    }
  }
  assert(unused.empty());
  cout << "! " << ret << endl;







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
