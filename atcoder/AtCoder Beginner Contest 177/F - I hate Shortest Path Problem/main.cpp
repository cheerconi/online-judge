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
const int bound = 1e6;
int tree[MAXN<<2], info[2][MAXN<<2];



void pushdown1(int node, int left, int right) {
  if (left == right || info[1][node] == 0) return;
  int mid = getmid;
  info[1][leftnode] = info[1][node];
  info[0][leftnode] = 0;
  tree[leftnode] = info[1][leftnode];
  info[1][rightnode] = info[1][node] + (mid+1 - left);
  info[0][rightnode] = 0;
  tree[rightnode] = info[1][rightnode];
  info[1][node] = 0;
}

void pushdown0(int node, int left, int right) {
  if (left == right || info[0][node] == 0) return;
  int mid = getmid;
  pushdown1(leftnode, left, mid);
  pushdown1(rightnode, mid+1, right);
  info[0][leftnode] += info[0][node];
  tree[leftnode] += info[0][node];
  info[0][rightnode] += info[0][node];
  tree[rightnode] += info[0][node];
  info[0][node] = 0;
}

void update0(int node, int left, int right, int i, int j) {
  if (i > j || j < left || right < i) return;
  pushdown1(node, left, right);
  if (i <= left && right <= j) {
    info[0][node]++;
    tree[node]++;
    return;
  }
  int mid = getmid;
  update0(leftnode, left, mid, i, j);
  update0(rightnode, mid+1, right, i, j);
  tree[node] = min(tree[leftnode], tree[rightnode]);
}


void update1(int node, int left, int right, int i, int j, int val) {
  if (i > j || right < i || j < left) return;
  if (i <= left && right <= j) {
    tree[node] = left-i+val;
    info[0][node] = 0;
    info[1][node] = left-i+val;
    return;
  }
  pushdown0(node, left, right);
  pushdown1(node, left, right);
  int mid = getmid;
  update1(leftnode, left, mid, i, j, val);
  update1(rightnode, mid+1, right, i, j, val);
  tree[node] = min(tree[leftnode], tree[rightnode]);
}

int query(int node, int left, int right, int i, int j) {
  if (i > j || right < i || j < left) return bound;
  if (i <= left && right <= j) return tree[node];
  int mid = getmid;
  if (info[0][node]) {
    pushdown0(node, left, right);
  } else if (info[1][node]) {
    pushdown1(node, left, right);
  }
  return min(query(leftnode, left, mid, i, j), query(rightnode, mid+1, right, i, j));
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
  // freopen("../output.txt", "w", stdout);
#endif
  int h, w; cin >> h >> w;
  for (int i = 0; i < h; i++) {
    int a, b; cin >> a >> b;
    update0(1, 1, w, 1, a-1);
    update0(1, 1, w, b+1, w);
    int x = query(1, 1, w, a-1, a-1);
    if (x >= bound) x = bound;
    update1(1, 1, w, a, b, x+1);
    x = query(1,1, w, 1, w);
    if (x >= bound) x = -1;
    cout << x << '\n';
  }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
