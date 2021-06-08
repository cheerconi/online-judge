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
pii pairs[MAXN];
int ret[MAXN];

int gcd(int a, int b) {
  if (a  > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b%a, a);
}

void solve(const string& s) {
  int n = s.size();
  int a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    ret[i] = 1;
    if (s[i] == 'D') a++;
    else b++;
    pairs[i] = {a, b};
  }
  set<pii> table;
  for (int i = 0; i < n; i++) {
    a = pairs[i].first;
    b = pairs[i].second;
    if (a== 0 || b == 0) {
      ret[i] = max(a, b);
      continue;
    }
    int c = gcd(a, b);
    a /= c;
    b /= c;
    if (!table.emplace(a, b).second) {
      continue;
    }
    int tot = 0;
    for (int j = a+b-1; j < n; j += a+b) {
      if (pairs[j].first % a == 0 && pairs[j].second % b == 0 && pairs[j].first/a == pairs[j].second/b) {
        tot++;
        ret[j] = max(ret[j], tot);
      }
    }
  }
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    solve(s);
    for(int i = 0; i < n; i++) {
      cout << ret[i];
      if (i+1 == n) cout << '\n';
      else cout << ' ';
    }
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
