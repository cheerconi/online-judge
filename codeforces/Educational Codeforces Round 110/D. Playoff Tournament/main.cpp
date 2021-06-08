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
const int MAXN = 6e5 + 10;
int cnt[MAXN];
string s;

void build(int i, int a, int b) {
  assert(i <  MAXN);
  if (a == b) {
    cnt[i] = 1;
    return;
  }
  int mid = (a+b) >> 1;
  build(2*i+1, a, mid);
  build (2*i, mid+1, b);
  int j = (int)s.size() - i;
  assert(j >= 0);
  if (s[j] == '0') cnt[i] = cnt[2*i+1];
  else if (s[j] == '1') cnt[i] = cnt[2*i];
  else cnt[i] = cnt[2*i+1] + cnt[2*i];
}






int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int k; cin >> k;
  int n = 1<<k;
  cin >> s;
  build (1, 1, n);
  int q; cin >> q;
  while (q--) {
    int j; cin >> j;
    char c; cin >> c;
    j--;
    s[j] = c;
    int i = (int)s.size() - j;
    assert (i >= 0);
    assert(2*i+1 < MAXN);
    while (i > 0) {
      cnt[i] = 0;
      assert(j >= 0 && j < s.size());
      if (s[j] != '1') cnt[i] += cnt[2*i+1];
      if (s[j] != '0') cnt[i] += cnt[2*i];
      i /= 2;
      j = (int)s.size() - i;
    }
    cout << cnt[1] << '\n';


  }







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
