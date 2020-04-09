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
const int MAXN = 1e6 + 10;
const int MAXM = 300000 + 10;
int sum[MAXN<<2], mar[MAXN<<2], a[MAXM], b[MAXM];

void update(int node, int left, int right, int idx, int val) {
  sum[node] += val;
  if (left == right) {
    mar[node] += val;
    return;
  }
  int mid = getmid;
  if (idx > mid) update(rightnode, mid+1, right, idx, val);
  else update(leftnode, left, mid, idx, val);
  mar[node] = max(mar[rightnode], mar[leftnode]+sum[rightnode]);
}

int query(int node, int left, int right, int base) {
  if (mar[node]+base <= 0) return -1;
  if (left == right) return left;
  int mid = getmid;
  if (mar[rightnode]+base > 0) return query(rightnode, mid+1, right, base);
  return query(leftnode, left, mid, base + sum[rightnode]);
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m, val, q; cin >> n >> m;
  int N = 1e6;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    update(1, 1, N, a[i], 1);
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    update(1, 1, N, b[i], -1);
  }
  cin >> q;
  while (q--) {
    cin >> n >> m >> val;
    if (n == 1) {
      update(1, 1, N, a[m], -1);
      a[m] = val;
      update(1, 1, N, val, 1);
    } else {
      update(1, 1, N, b[m], 1);
      b[m] = val;
      update(1, 1, N, val, -1);
    }
    cout << query(1, 1, N, 0) << '\n';
  }








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
