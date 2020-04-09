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

inline char get(void) {
  static char buf[100000], *S = buf, *T = buf;
  if (S == T) {
    T = (S = buf) + fread(buf, 1, 100000, stdin);
    if (S == T) return EOF;
  }
  return *S++;
}

inline void read(int &x) {
  static char c; x = 0; int sgn = 0;
  for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
  for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
  if (sgn) x = -x;
}


const int MAXN = 1e6 + 10;
int nums[MAXN];
LL ret[MAXN];





int main() {
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, w, m, val; read(n); read(w);
  for (int i = 0; i < n; i++) {
    read(m);
    int sz = w - m + 1;
    map<int, int> table;
    int cnt = 0;
    for (int j = 0; j < w;) {
      if (j < m) {
        read(nums[j]);
        table[nums[j]]++;
        cnt++;
      }
      int k = j - sz;
      if (k >= 0 && k < m) {
        auto it = table.find(nums[k]);
        it->second--;
        if (it->second == 0) table.erase(it);
        cnt--;
      }
      auto it = table.end();
      it--;
      val = it->first;
      if (cnt < sz) val = max(val, 0);
      if (cnt == m && j < w-m && j >= m) {
        k = w-m;
      } else {
        k = j+1;
      }
      ret[j] += val;
      ret[k] -= val;
      j = k;
    }
  }
  for (int i = 0; i < w; i++) {
    if (i-1 >= 0) ret[i] += ret[i-1];
    printf("%lld", ret[i]);
    if (i == w-1) printf("\n");
    printf(" ");
  }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
