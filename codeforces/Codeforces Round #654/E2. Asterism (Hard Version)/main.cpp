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
const int MAXN = 1e5 + 10;
int a[MAXN], sum[MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
  // freopen("../output.txt", "w", stdout);
#endif
  int n, p; cin >> n >> p;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);
  int base = a[n-1] - n + 1;
  int mi = 0;
  for (int i = 0; i < n; i++) {
    mi = max(mi, a[i]-i);
    int j = i+p - 1;
    if (j >= n) continue;
    int tmp = a[j] - i;
    tmp = max(tmp-base, 0);
    sum[tmp]++;
  }
  vector<int> ret;
  for (int i = 0; i < MAXN; i++) {
    if (i-1 >= 0) sum[i] += sum[i-1];
    if (sum[i] > 0 || i+base < mi) continue;
    ret.push_back(i + base);
  }
  cout << ret.size() << '\n';
  for (int i = 0; i < ret.size(); i++) {
    cout << ret[i];
    if (i+1 == ret.size()) cout << '\n';
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
