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

const int MAXN = 4e5 + 10;
int tree[MAXN<<2], info[MAXN<<2];

void push_down(int node, int left, int right) {
  if (info[node] == 0 || left == right) return;
  tree[leftnode] += info[node];
  tree[rightnode] += info[node];
  info[leftnode] += info[node];
  info[rightnode] += info[node];
  info[node] = 0;
  tree[node] = max(tree[leftnode], tree[rightnode]);
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

int query(int node, int left, int right, int i, int j) {
  if (j < left || right < i) return INT_MIN;
  if (i <= left && right <= j) return tree[node];
  push_down(node, left, right);
  int mid = getmid;
  return max(query(leftnode, left, mid, i, j), query(rightnode, mid+1, right, i, j));
}

void build(int node, int left, int right) {
  if (left == right) {
    tree[node] = left - 1;
    return;
  }
  int mid = getmid;
  build(leftnode, left, mid);
  build(rightnode, mid+1, right);
  tree[node] = max(tree[leftnode], tree[rightnode]);
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
  // freopen("../output.txt", "w", stdout);
#endif
  int N = 4e5;
  build(1, 1, N);
  int n, k, m;
  cin >> n >> k >> m;
  set<pii> table;
  map<int, int> range;
  for (int i = 0; i < m; i++) {
    pii item;
    cin >> item.first >> item.second;
    int x = item.second + abs(item.first - k);
    if (table.find(item) == table.end()) {
      table.insert(item);
      range[x]++;
      update(1, 1, N, 1, x, 1);
    } else {
      table.erase(item);
      auto it = range.find(x);
      it->second--;
      if (it->second == 0) range.erase(it);
      update(1, 1, N, 1, x, -1);
    }
    int ret = n;
    if (!range.empty()) {
      ret = query(1, 1, N, 1, range.rbegin()->first);
    }
    cout << max(ret, n) - n << '\n';



  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */