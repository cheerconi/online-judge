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
pii a[MAXN], b[MAXN];
int x[MAXN], y[MAXN], z[MAXN], idx[MAXN];
LL tree[MAXN<<2], info[MAXN<<2];

int simp(pii nums[], int n) {
  sort(nums, nums+n, greater<pii>());
  vector<pii> tmp;
  for (int i = 0; i < n; i++) {
    if (tmp.empty()) {
      tmp.push_back(nums[i]);
      continue;
    }
    if (tmp.back().first == nums[i].first) {
      tmp.back().second = nums[i].second;
      continue;
    }
    if (tmp.back().second > nums[i].second) {
      tmp.push_back(nums[i]);
    }
  }
  n = tmp.size();
  for (int i = 0; i < n; i++) {
    nums[n-i-1] = tmp[i];
  }
  return n;
}

void pushdown(int node, int left, int right) {
  if (info[node] == 0 || left == right) return;
  int mid = getmid;
  tree[leftnode] += info[node];
  info[leftnode] += info[node];
  tree[rightnode] += info[node];
  info[rightnode] += info[node];
  info[node] = 0;
}

void build(int node, int left, int right) {
  if (left == right) {
    tree[node] = -b[left-1].second;
    return;
  }
  int mid = getmid;
  build(leftnode, left, mid);
  build(rightnode, mid+1, right);
  tree[node] = max(tree[leftnode], tree[rightnode]);
}

void update(int node, int left, int right, int i, int j, LL val) {
  if (right < i || j < left) return;
  if (i <= left && right <= j) {
    info[node] += val;
    tree[node] += val;
    return;
  }
  pushdown(node, left, right);
  int mid = getmid;
  update(leftnode, left, mid, i, j, val);
  update(rightnode, mid+1, right, i, j, val);
  tree[node] = max(tree[leftnode], tree[rightnode]);
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m, p; cin >> n >> m >> p;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i].first >> b[i].second;
  }
  for (int i = 0; i < p; i++) {
    cin >> x[i] >> y[i] >> z[i];
    idx[i] = i;
  }
  n = simp(a, n);
  m = simp(b, m);
  build(1, 1, m);
  sort(idx, idx+p, [](int i, int j) {return x[i] < x[j];});
  LL ret = LLONG_MIN;
  int u = 0;
  for (int i = 0; i < n; i++) {
    while (u < p && x[idx[u]] < a[i].first) {
      int v = upper_bound(b, b+m, make_pair(y[idx[u]], INT_MAX)) - b;
      if (v+1 <= m) update(1, 1, m, v+1, m, z[idx[u]]);
      u++;
    }
    ret = max(tree[1] - a[i].second, ret);
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
