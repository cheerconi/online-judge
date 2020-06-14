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
const int MAXN = 2333;
int ret[MAXN][MAXN], zeros[11];

void ask(int i, int j) {
  assert(i != j);
  if (ret[i][j] == 0) {
    cout << "? " << i << ' ' << j << endl;
    cin >> ret[i][j];
    ret[j][i] = ret[i][j];
  }
}

int query(int idx, int m) {
  int mask = (1<<m) - 1;
  for (int i = 0; i < m; i++) {
    if (zeros[i] == idx) {
      if (mask & (1<<i)) mask ^= 1<<i;
    } else {
      ask(idx, zeros[i]);
      mask &= ret[idx][zeros[i]];
    }
  }
  return mask;
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
//  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int m = 0;
  while ((1<<m) <= n) {
    m++;
  }
  vector<pii> cands;
  for (int i = 1; i <= n; i++) {
    for (int j = i+1; j <= n; j++) {
      cands.emplace_back(i, j);
    }
  }
  while (!cands.empty()) {
    int idx = mt() % cands.size();
    swap(cands[idx], cands.back());
    ask(cands.back().first, cands.back().second);
    for (int k = 0; k < m; k++) {
      if ((1<<k) & ret[cands.back().first][cands.back().second]) continue;
      zeros[k] = cands.back().first;
    }
    bool flag = true;
    for (int i = 0; i < m && flag; i++) {
      if (zeros[i] == 0) flag = false;
    }
    cands.pop_back();
    if (flag) break;
  }
  int idx = 1;
  int val = query(idx, m);
  for (int j = 2; j <= n && val > 0; j++) {
    ask(j, idx);
    if (ret[j][idx]== val) {
      idx = j;
      val = query(idx, m);
    }
  }
  assert(val == 0);
  vector<int> vs;
  for (int i = 1; i <= n; i++){
    if (i == idx) vs.push_back(0);
    else {
      ask(i, idx);
      vs.push_back(ret[i][idx]);
    }
  }
  cout << "!";
  for (int num : vs) {
    cout << ' ' << num;
  }
  cout << endl;






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
