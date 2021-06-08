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
const int MAXN = 2e5 + 10;
string mat[MAXN];
int cnt[66];
int valid[66];
map<int, int> table;
bool connect[32][32];
int ret = 0;
int ret_mask = 0;
int n;

void dfs(int i, int tot, int mask, int ban, int len) {
  if (i == tot) {
    if (len > ret) {
      ret = len;
      ret_mask = mask;
    }
    return;
  }
  if (tot-i+len <= ret) return;
  bool not_add = ban & (1<<i);
  int new_mask = mask | (1<<i);
  if (!not_add) {
    int tmp = 0;
    for (const auto& item : table) {
      if ((new_mask & item.first) == new_mask) tmp += item.second;
      if (tmp*2 >= n) break;
    }
    if (tmp*2 < n) not_add = true;
  }

  if (!not_add) {
    int new_ban = ban;
    for (int j = i+1; j < tot; j++) {
      if (!connect[i][j]) new_ban = new_ban | (1<<j);
    }
    dfs(i+1, tot, new_mask, new_ban, len+1);
  }
  dfs(i+1, tot, mask, ban, len);
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int m, p; cin >> n >> m >> p;
  for (int i = 0; i < n; i++) {
    cin >> mat[i];
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == '1') cnt[j]++;
    }
  }
  memset(valid, -1, sizeof(valid));
  int tot = 0;
  for (int i = 0; i < m; i++) {
    if (cnt[i] * 2 >= n) {
      valid[i] = tot;
      tot++;
    }
  }
  for (int i = 0; i < n; i++) {
    int val = 0;
    for (int j = 0; j < m; j++) {
      if (valid[j] == -1 || mat[i][j] == '0') continue;
      val += 1<<valid[j];
    }
    table[val]++;
  }
  for (int i = 0; i < tot; i++) {
    for (int j = i+1; j < tot; j++) {
      int mask = (1<<i)  | (1<<j);
      int tmp = 0;
      for (const auto& item : table) {
        if ((mask & item.first) == mask) {
          tmp += item.second;
          if (tmp*2 >= n) break;
        }
      }
      if (tmp*2 >= n) {
        connect[i][j] = true;
        connect[j][i] = true;
      }
    }
  }
  dfs(0, tot, 0, 0, 0);
  for (int i = 0; i < m; i++) {
    if (valid[i] != -1 && ((1<<valid[i]) & ret_mask)) cout << '1';
    else cout << '0';
  }
  cout << '\n';








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
