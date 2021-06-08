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
const int e = 1e6;
int tree[e];

int lowbit(int i) {
  return i&(-i);
}

void add(int i) {
  while (i < e) {
    tree[i]++;
    i += lowbit(i);
  }
}

int query(int i) {
  int ret = 0;
  while (i > 0) {
    ret += tree[i];
    i -= lowbit(i);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m; cin >> n >> m;
  LL ret = 1;
  vector<vector<int>> rows;
  for (int i = 0; i < n; i++) {
    int y, a, b; cin >> y >> a >> b;
    rows.push_back({y, a, b});
    if (a == 0 && b == e) ret++;
  }
  vector<vector<int>> up, down;
  for (int i = 0; i < m; i++) {
    int x, a, b; cin >> x >> a >> b;
    if (a == 0) {
      down.push_back({x, a, b});
    } else {
      up.push_back({x, a, b});
    }
    if (a == 0 && b == e) ret++;
  }


  sort(rows.begin(), rows.end());
  sort(up.begin(), up.end(), [](const vector<int>& x, const vector<int>& y){return x[1] < y[1];});
  sort(down.begin(), down.end(), [](const vector<int>& x, const vector<int>& y){return x[2] > y[2];});

  int j = 0;
  for (const auto& row : rows) {
    while (j < up.size() && row[0] >= up[j][1]) {
      add(up[j][0]);
      j++;
    }
    if (row[2] != e) {
      ret += query(row[2]);
    } else {
      ret += j;
      if (row[1] > 1) ret -= query(row[1]-1);
    }
  }

  memset(tree, 0, sizeof(tree));
  j = 0;
  for (int i = (int)rows.size()-1; i >= 0; i--) {
    const auto& row = rows[i];
    while (j < down.size() && row[0] <= down[j][2]) {
      add(down[j][0]);
      j++;
    }
    if (row[2] != e) {
      ret += query(row[2]);
    } else {
      ret += j;
      if (row[1] > 1) ret -= query(row[1]-1);
    }
  }
  cout << ret << endl;








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
