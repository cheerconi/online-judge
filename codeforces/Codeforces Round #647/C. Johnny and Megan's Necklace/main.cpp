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
const int MAXN = 5e5 + 10;
const int MAXM = 1<<20;
int nums[MAXN<<1], cnt[MAXM], par[MAXM];
vi ret;
vector<pii> edges[MAXN + MAXM];
bool used[2*MAXN];

int find(int i) {
  if (par[i] == i) return i;
  return par[i]=find(par[i]);
}

void add(int i, int j) {
  int x = find(i);
  int y = find(j);
  par[x] = y;
}

void add(int i, int j, int idx) {
  edges[i].emplace_back(j, idx);
  edges[j].emplace_back(i, idx);
}

void dfs(int cur, int idx) {
  used[idx] = true;
  while (!edges[cur].empty()) {
    pii item = edges[cur].back();
    edges[cur].pop_back();
    if (!used[item.second]) dfs(item.first, item.second);
  }
  ret.push_back(idx);
}

bool solve(int mask, int n) {
  for (int i = 0; i < mask; i++) {
    cnt[i] = 0;
    par[i] = i;
  }
  for (int i = 0; i < n; i++) {
    nums[i*2] %= mask;
    nums[i*2+1] %= mask;
    cnt[nums[i*2]]++;
    cnt[nums[i*2+1]]++;
    add(nums[i*2], nums[i*2+1]);
  }
  int root = find(nums[0]);
  for (int i = 0; i < mask; i++) {
    if (cnt[i] % 2 != 0) return false;
    if (cnt[i] == 0) continue;
    if (root != find(i)) return false;
  }
  for (int i = 0; i < n; i++) {
    add(nums[i*2], i+mask, i*2);
    add(nums[i*2+1], i+mask, i*2+1);
  }
  dfs(mask, 0);
  return true;
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
    cin >> nums[i*2] >> nums[i*2+1];
  }
  for (int i = 20; i >= 0; i--) {
    if (solve(1<<i, n)) {
      cout << i << '\n';
      break;
    }
  }
  for (int i = 0; i < 2*n; i++) {
    cout << ret[i] + 1;
    if (i+1 == 2*n) cout << '\n';
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
