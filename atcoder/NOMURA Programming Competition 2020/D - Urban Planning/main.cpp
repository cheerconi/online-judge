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
const int mod = 1e9 + 7;
const int MAXN = 5000 + 10;
int p[MAXN], par[MAXN], cnt[MAXN], dp[MAXN][MAXN], fact[MAXN];
bool has[MAXN];

int find(int i) {
  if (par[i] == i) return i;
  return par[i]=find(par[i]);
}

void add(int i, int j) {
  int a = find(i);
  int b = find(j);
  par[a] = b;
}

LL power(LL base, LL p) {
  LL ret = 1;
  base = base % mod;
  while (p) {
    if (p&1) ret = ret * base % mod;
    p >>= 1;
    base = base * base % mod;
  }
  return ret;
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  LL n; cin >> n;
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = 1LL * fact[i-1] * i % mod;
  }
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    par[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (p[i] == -1) continue;
    add(i, p[i]);
  }
  vector<int> nums;
  int a = 0;
  for (int i = 1; i <= n; i++) {
    int tmp = find(i);
    cnt[tmp]++;
    if (cnt[tmp] == 1) a++;
    if (p[i] == -1) {
      assert(!has[tmp]);
      has[tmp] = true;
      nums.push_back(tmp);
    }
  }
  int b = nums.size();
  a = a - b;
  LL ret = power(n-1, b) * (n-a) % mod;
  dp[0][0] = 1;
  for (int i = 0; i < b; i++) {
    for (int j = 0; j <= i+1; j++) {
      dp[i+1][j] = dp[i][j];
      if (j-1 >= 0) dp[i+1][j] = (dp[i+1][j] + (LL)dp[i][j-1] * cnt[nums[i]] % mod) % mod;
    }
  }
  for (int i = 2; i <= b; i++) {
    LL tmp = power(n-1, b-i) * dp[b][i] % mod * fact[i-1] % mod;
    ret = (ret - tmp + mod) % mod;
  }
  if (b >= 1) {
    LL tmp = power(n-1, b-1);
    for (int i : nums) {
      ret = (ret - tmp * (cnt[i]-1) % mod + mod) % mod;
    }
  }

  cout << ret << '\n';













/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
