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
int tree[2][MAXN<<2], nums[MAXN], sum[2][MAXN];

vi idx[100];

void update(int node, int left, int right, int x, int i, int val) {
  if (left == right) {
    tree[x][node] = val;
    return;
  }
  int mid = getmid;
  if (i <= mid) update(leftnode, left, mid, x, i, val);
  else update(rightnode, mid+1, right, x, i, val);
  tree[x][node] = max(tree[x][leftnode], tree[x][rightnode]);
}

int query(int node, int left, int right, int x, int i, int j) {
  if (j < left || right < i) return INT_MIN;
  if (i <= left && right <= j) return tree[x][node];
  int mid = getmid;
  return max(query(leftnode, left, mid, x, i, j), query(rightnode, mid+1, right, x, i, j));
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int base = 30;
  for (int i = 1; i <= n; i++) {
    cin >> nums[i];
    idx[nums[i]+base].push_back(i);
    sum[0][i] = nums[i] + sum[0][i-1];
    update(1, 1, n, 0, i, sum[0][i]);
  }
  for (int i = n; i >= 1; i--) {
    sum[1][i] = nums[i] + sum[1][i+1];
    update(1, 1, n, 1, i, sum[1][i]);
  }
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    int a = 1, b = n;
    for (int j = nums[i]+1; j <= 30; j++) {
      int x = lower_bound(idx[j+base].begin(), idx[j+base].end(), i) - idx[j+base].begin();
      if (x < idx[j+base].size()) b = min(b, idx[j+base][x]-1);
      x--;
      if (x >= 0) a = max(a, idx[j+base][x]+1);
    }
    assert(a <= i);
    int tmp = query(1, 1, n, 1, a, i) - sum[1][i+1];
    assert(b >= i);
    tmp += query(1, 1, n, 0, i, b) - sum[0][i-1];
    tmp -= 2*nums[i];
    ret = max(ret, tmp);
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
