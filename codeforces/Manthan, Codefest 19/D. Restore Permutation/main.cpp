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
const int MAXN = 2e5 + 10;
LL tree[MAXN<<2], delta[MAXN<<2];
int ret[MAXN];

void update(int node, int left, int right, int a, int b, LL val) {
  if (right < a || b < left) return;
  if (a <= left && right <= b) {
    tree[node] += val;
    delta[node] += val;
    return;
  }
  int mid = getmid;
  if (delta[node] != 0) {
    update(leftnode, left, mid, left, mid, delta[node]);
    update(rightnode, mid+1, right, mid+1, right, delta[node]);
    delta[node] = 0;
  }
  update(leftnode, left, mid, a, b, val);
  update(rightnode, mid+1, right, a, b, val);
  tree[node] = min(tree[leftnode], tree[rightnode]);
}

LL query(int node, int left, int right, int a, int b) {
  if (right < a || b < left) return LLONG_MAX;
  if (a <= left && right <= b) return tree[node];
  int mid = getmid;
  if (delta[node] != 0) {
    update(leftnode, left, mid, left, mid, delta[node]);
    update(rightnode, mid+1, right, mid+1, right, delta[node]);
    delta[node] = 0;
  }
  return min(query(leftnode, left, mid, a, b), query(rightnode, mid+1, right, a, b));
}

int solve(int n, int val) {
  int a = 1, b = n;
  while (a < b) {
    int mid = (a+b) >> 1;
    int tmp = query(1, 1, n, mid+1, b);
    if (tmp == 0) a = mid+1;
    else b = mid;
  }
  update(1, 1, n, a, a, 1e12);
  if(a+1 <= n) update(1, 1, n, a+1, n, -val);
  return a;
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n;
  LL val;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> val;
    update(1, 1, n, i, i, val);
  }
  for (int i = 1; i <= n; i++) {
    int idx = solve(n, i);
    ret[idx] = i;
  }
  for (int i = 1; i <= n; i++) {
    cout << ret[i];
    if (i == n) cout << endl;
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
