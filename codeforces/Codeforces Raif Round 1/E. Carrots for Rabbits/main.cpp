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
LL split(LL val, int n) {
  assert(val >= n);
  LL a = val / n;
  LL b = val % n;
  LL ret = (n-b) * a * a;
  ret += b * (a+1) * (a+1);
  return ret;
}

LL get_diff(LL val, int n) {
  LL diff = 0;
  if (val >= n+1) {
    diff = split(val, n) - split(val, n+1);
  }
  return diff;
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, k; cin >> n >> k;
  int cnt = n;
  LL ret = 0;
  priority_queue<vector<LL>> pq;
  for (int i = 0; i < n; i++) {
    LL val; cin >> val;
    pq.push({get_diff(val, 1), val, 1});
    ret += val * val;
  }
  while (cnt < k) {
    assert(!pq.empty());
    vector<LL> item = pq.top(); pq.pop();
    LL val = item[1];
    assert(item[1] >= item[2]+1);
    ret -= item[0];
    pq.push({get_diff(val, item[2]+1), val, item[2]+1});
    cnt++;
  }
  cout << ret << '\n';







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
