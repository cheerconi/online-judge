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
const int MAXN = 300000 + 10;
int nums[MAXN], tree[MAXN<<2], info[MAXN<<2];

void push_down(int node, int left, int right) {
  if (info[node] == 0 || left ==right) return;
  info[leftnode] += info[node];
  tree[leftnode] += info[node];
  info[rightnode] += info[node];
  tree[rightnode] += info[node];
  info[node] = 0;
}

void update(int node, int left, int right, int i, int j, int val) {
  if (j < left || right < i) return;
  if (i <= left && right <= j) {
    info[node] += val;
    tree[node] += val;
    return;
  }
  push_down(node, left, right);
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
  int n, val; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> val;
    nums[val] = i;
  }
  int cur = n;
  update(1, 1, n, 1, nums[cur], 1);
  for (int i = 0; i < n; i++) {
    while(tree[1] <= 0) {
      cur--;
      assert(cur >= 1);
      update(1, 1, n, 1, nums[cur], 1);
    }
    cout << cur;
    if (i+1 == n) cout << '\n';
    else cout << ' ';
    cin >> val;
    update(1, 1, n, 1, val, -1);
  }







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
