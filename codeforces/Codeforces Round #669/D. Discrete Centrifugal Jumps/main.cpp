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
const int MAXN = 3e5 + 10;
int a[MAXN], b[MAXN], nums[MAXN], idx[MAXN];
bool used[MAXN];
vector<int> edges[MAXN];

int find(int i, int x[]) {
  if (x[i] == i) return i;
  return x[i] = find(x[i], x);
}

void add(int i, int j) {
  int x = find(i, a);
  int y = find(j ,a);
  a[max(x, y)] = min(x, y);

  x = find(i, b);
  y = find(j, b);
  b[min(x, y)] = max(x, y);
}

int solve(int n) {
  int ret = 0;
  memset(used, false, sizeof(used));
  queue<int> q;
  q.push(0);
  used[0] = true;
  while (!q.empty()) {
    int sz = q.size();
    ret++;
    while (sz--) {
      int cur = q.front(); q.pop();
      for (int nxt : edges[cur]) {
        if (used[nxt]) continue;
        if (nxt == n-1) return ret;
        used[nxt] = true;
        q.push(nxt);
      }
    }
  }
  assert(false);
  return -1;
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
    cin >> nums[i];
    idx[i] = i;
    if (i+1 < n) edges[i].push_back(i+1);
  }
  sort(idx, idx+n, [](int i, int j) {return nums[i] < nums[j];});
  for (int i = 0; i < n; i++) {
    a[i] = i;
    b[i] = i;
  }
  for (int i = 0; i < n; i++) {
    int j = idx[i];
    used[j] = true;
    if (j-1 >= 0 && used[j-1]) add(j-1, j);
    if (i+1 < n && used[j+1]) add(j+1, j);
    int x = find(j, a);
    int y = find(j, b);
    if (x-1 >= 0 && y+1 < n && nums[x-1] != nums[j] && nums[y+1] != nums[j]) edges[x-1].push_back(y+1);
  }
  for (int i = 0; i < n; i++) {
    a[i] = i;
    b[i] = i;
    used[i] = false;
  }
  for (int i = n-1; i >= 0; i--) {
    int j = idx[i];
    used[j] = true;
    if (j-1 >= 0 && used[j-1]) add(j-1, j);
    if (i+1 < n && used[j+1]) add(j+1, j);
    int x = find(j, a);
    int y = find(j, b);
    if (x-1 >= 0 && y+1 < n && nums[x-1] != nums[j] && nums[y+1] != nums[j]) edges[x-1].push_back(y+1);
  }
  cout << solve(n) << endl;











/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
