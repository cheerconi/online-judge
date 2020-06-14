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
const int MAXN = 1e7 + 10;
const int MAXM = 5e5 + 10;
int fact[MAXN];
int a[MAXM], b[MAXM];




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  for (int i = 2; i < MAXN; i++) {
    if (fact[i] != 0) continue;
    for (int j = i+i; j < MAXN; j += i) {
      fact[j] = i;
    }
  }
  int n, val; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> val;
    int tmp = val;
    map<int, int> table;
    while (fact[val] > 0) {
      table[fact[val]]++;
      val /= fact[val];
    }
    if (val > 1) table[val]++;
    if (table.size() == 1) {
      a[i] = -1;
      b[i] = -1;
    } else {
      int m = table.begin()->first;
      while (tmp % m == 0) tmp /= m;
      a[i] = tmp;
      b[i] = m;
    }

  }
  for (int i = 0; i < n; i++) {
    cout << a[i];
    if (i+1 == n) cout << '\n';
    else cout << ' ';
  }
  for (int i = 0; i < n; i++) {
    cout << b[i];
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
