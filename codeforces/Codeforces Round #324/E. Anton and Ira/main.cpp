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
const int MAXN = 2000 + 10;
int p[MAXN], s[MAXN], t[MAXN];
int tree[MAXN<<2];

void update(int node, int left, int right, int i, int val) {
  if (left == right) {
    tree[node] = val;
    return;
  }
  int mid = getmid;
  if (i <= mid) update(leftnode, left, mid, i, val);
  else update(rightnode, mid+1, right, i, val);
  tree[node] = max(tree[leftnode], tree[rightnode]);
}

int query(int node, int left, int right, int i, int j) {
  if (j < left || right < i) return -1;
  if (i <= left && right <= j) return tree[node];
  int mid = getmid;
  return max(query(leftnode, left, mid, i, j), query(rightnode, mid+1, right, i, j));
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    s[p[i]] = i;
  }
  int val;
  for (int i = 0; i < n; i++) {
    cin >> val;
    p[s[val]+1] = i+1;
    t[i+1] = s[val]+1;

  }
  for (int i = 1; i <= n; i++) {
    update(1, 1, n, i, p[i]);
  }
  int ret = 0;
  vector<pii> ms;
  for (int i = 1; i <= n; i++) {
    int idx = t[i];
    while (idx != i) {
      int nxt = query(1, 1, n, 1, idx-1);
      nxt = t[nxt];
      ms.emplace_back(nxt, idx);
      ret += abs(nxt - idx);
      swap(p[nxt], p[idx]);
      update(1, 1, n, idx, p[idx]);
      update(1, 1, n, nxt, p[nxt]);
      t[p[idx]] = idx;
      t[p[nxt]] = nxt;
      idx = nxt;
    }
  }
  cout << ret << '\n' << ms.size() << '\n';
  for (const auto& item : ms) {
    cout << item.first << ' ' << item.second << '\n';
  }



  







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
