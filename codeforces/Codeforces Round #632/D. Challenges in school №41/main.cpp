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
const int MAXN = 3300;
int cnt[MAXN], t[MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, k; cin >> n >> k;
  string s; cin >> s;
  int i = 0;
  for (; i < n; i++) {
    if (s[i] == 'R') break;
    t[i] = 0;
  }
  LL ma = 0, mi = 0;
  for (; i < n; i++) {
    if (i-1 >= 0) cnt[i] += cnt[i-1];
    if (s[i] == 'R') cnt[i]++;
    else {
      int idx = i - cnt[i];
      t[idx] = cnt[i];
      ma += cnt[i];
      if (idx -1 >= 0) t[idx] = max(t[idx-1] + 1, t[idx]);
      mi = t[idx];
    }
  }
  if (k > ma || k < mi) {
    cout << -1 << '\n';
    return 0;
  }
  queue<int> q;
  for (int j = 0; j+1 < n; j++) {
    if (s[j] == 'R' && s[j+1] == 'L') q.push(j);
  }
  while(k--) {
    LL sz = q.size();
    sz = min(sz, ma-k);
    ma -= sz;
    cout << sz << ' ';
    for (int j = 0; j < sz; j++) {
      int cur = q.front(); q.pop();
      swap(s[cur], s[cur+1]);
      if (cur+2 < n && s[cur+2] == 'L') q.push(cur+1);
      if (cur-1 >= 0 && s[cur-1] == 'R') q.push(cur-1);
      cout << cur+1;
      if (j+1 == sz) cout << '\n';
      else cout << ' ';
    }
  }
  assert(q.empty());











/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
