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
const int MAXN = 2000 + 10;
int tot = 0;
int par[MAXN];

vi ask(int i, int n) {
  tot++;
  assert(tot <= (n+1)/2);
  cout << "? " << i+1 << endl;
  vi ret(n);
  for (int j = 0; j < n; j++) {
    cin >> ret[j];
  }
  return ret;
}


int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
//  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  memset(par, -1, sizeof(par));
  int n; cin >> n;
  vi node2layer = ask(0, n);
  int m = 0;
  for (int num : node2layer) {
    m = max(m, num);
  }
  vector<vi> layers(m+1);
  for (int i = 0; i < n; i++) {
    layers[node2layer[i]].push_back(i);
  }
  for (int node : layers[1]) {
    par[node] = 0;
  }
  int cnt = 0;
  for (int i = 1; i <= m; i += 2) {
    cnt += layers[i].size();
  }
  int j = 1;
  if (n-1-cnt < cnt) j = 2;
  for (; j <= m; j += 2) {
    for (int node : layers[j]) {
      vi ret = ask(node, n);
      for (int k = 0; k < n; k++) {
        if (ret[k] == 1) {
          if (node2layer[k] < node2layer[node]) {
            par[node] = k;
          } else {
            par[k] = node;
          }
        }
      }
    }
  }
  cout << "!" << endl;
  for (int i = 1; i < n; i++) {
    cout << i+1 << ' ' << par[i]+1 << endl;
  }








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
