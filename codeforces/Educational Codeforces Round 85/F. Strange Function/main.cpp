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


const int MAXN = 5e5 + 10;
int a[MAXN], p[MAXN], b[MAXN];

LL tree[MAXN<<2], cache[MAXN<<2];

void pushdown(int node, int left, int right) {
  if (cache[node] == 0) return;
  if (left == right) {
    if (tree[node] != LLONG_MAX) {
      tree[node] += cache[node];
    }
  } else {
    int mid = getmid;
    cache[leftnode] += cache[node];
    cache[rightnode] += cache[node];
  }
  cache[node] = 0;
}

void update(int node, int left, int right, int i, int j, LL val) {
  if (j < left || right < i) return;
  if (i <= left && right <= j) {
    cache[node] += val;
    return;
  }
  int mid = getmid;
  update(leftnode, left, mid, i, j, val);
  update(rightnode, mid+1, right, i, j, val);
}


void update(int node, int left, int right, int i, LL val) {
  pushdown(node, left, right);
  if (left == right) {
    tree[node] = val;
    return;
  }
  int mid = getmid;
  if (i <= mid) update(leftnode, left, mid, i, val);
  else update(rightnode, mid+1, right, i, val);
}

LL query(int node, int left, int right, int i) {
  pushdown(node, left, right);
  if (left == right) {
    return tree[node];
  }
  int mid = getmid;
  if (i <= mid) return query(leftnode, left, mid, i);
  return query(rightnode, mid+1, right, i);
}

void init(int node, int left, int right) {
  if (left == right) {
    tree[node] = LLONG_MAX;
    return;
  }
  int mid = getmid;
  init(leftnode, left, mid);
  init(rightnode, mid+1, right);
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> p[i];
  int m; cin >> m;
  for (int i = 1; i <= m; i++) cin >> b[i];
  init(1, 1, m);
  LL sum = 0;
  for (int i = 0; i < n; i++) {
    int idx = lower_bound(b+1, b+m+1, a[i]) - b;
    if (idx <= m && b[idx] == a[i]) {
      LL tmp = sum;
      if (idx > 1) tmp  = query(1, 1, m, idx-1);
      LL tmp2 = query(1, 1, m, idx);
      if (tmp2 != LLONG_MAX) {
        tmp2 = min(tmp2, tmp2 + p[i]);
      }
      tmp = min(tmp, tmp2);
      update(1, 1, m, idx, tmp);
    }
    int idx2 = idx;
    if (idx <= m && b[idx] == a[i]) idx2++;
    LL val = min(0, p[i]);
    if (val != 0 && idx2 <= m) update(1, 1, m, idx2, m, val);
    idx2 = idx - 1;
    val = p[i];
    if (val != 0 && idx2 > 0) update(1, 1, m, 1, idx2, val);
    sum += p[i];
  }
  LL ret = query(1, 1, m, m);
  if (ret == LLONG_MAX) {
    cout << "NO\n";
  } else {
    cout << "YES\n" << ret << "\n";
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
