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
LL a[MAXN], b[MAXN];
vi edges[MAXN];
vi idx[MAXN][2];
LL ret;
bool son[MAXN];
vi idx_list;

LL dfs(int cur) {
  LL val = 0;
  for (int nxt : edges[cur]) {
    LL tmp = dfs(nxt);
    if (tmp > 0) {
      val += tmp;
      idx[cur][0].push_back(nxt);
    } else {
      idx[cur][1].push_back(nxt);
    }
  }
  if (val > 0) {
    ret += val + a[cur];
    return val + a[cur];
  }
  ret += a[cur];
  return a[cur];
}

void get_list(int cur) {
  for (int nxt : idx[cur][0]) get_list(nxt);
  idx_list.push_back(cur);
  for (int nxt : idx[cur][1]) get_list(nxt);
}






int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    if (b[i] != -1) {
      edges[b[i]].push_back(i);
      son[i] = true;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (son[i]) continue;
    dfs(i);
    get_list(i);
  }
  cout << ret << '\n';
  for (int i = 0; i < n; i++) {
    cout << idx_list[i];
    if (i+1 == n) cout << '\n';
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
