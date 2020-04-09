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

const int MAXN = (1<<20) + 10;
int nums[MAXN];
bool state[MAXN], keep[MAXN];

void solve(int i, int n) {
  int a = i*2;
  if (a > n || (nums[a] == 0 && nums[a+1] == 0)) {
    nums[i] = 0;
    state[i] = false;
    return;
  }
  if (nums[a+1] > nums[a]) a += 1;
  nums[i] = nums[a];
  assert(state[a]);
  solve(a, n);
  if (keep[i]) {
    if (nums[i*2+1] == 0 && nums[i*2] == 0) state[i] = false;
    a = i*2;
    if (nums[a] < nums[a+1]) a++;
    state[i] = state[a];
  }
}



int main() {
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int t; read(t);
  while (t--) {
    int h, g; read(h); read(g);
    int n = (1<<h) - 1;
    int m =  n - ((1<<g) - 1);
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
      state[i] = true;
      read(nums[i]);
      sum += nums[i];
      if (i < (1<<g)) keep[i] = true;
      else keep[i] = false;
    }
    vector<int> ret;
    ret.reserve(m);
    for (int i = 1; m > 0; i++) {
      while (state[i] && m > 0) {
        sum -= nums[i];
        m--;
        solve(i, n);
        ret.push_back(i);
      }
    }
    assert(m == 0);
    printf("%lld\n", sum);
    for (int i = 0; i < ret.size(); i++) {
      printf("%d", ret[i]);
      if (i+1 == ret.size()) printf("\n");
      else printf(" ");
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
