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
int dp[MAXN][MAXN];
int nums[MAXN], ps[12], ret[MAXN];
map<int, int> table[2000];
vector<string> pps{"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};


int to_int(const string& s) {
  int val = 0;
  for (char c : s) {
    val = val * 2 + c -'0';
  }
  return val;
}


int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  map<int, int> rp;
  for (int i = 0; i  <= 9; i++) {
    ps[i] = to_int(pps[i]);
    rp[ps[i]] = i;
  }
  int mask = 1<<7;
  for (int i = 0; i < mask; i++) {
    for (int j = 0; j <= 9; j++) {
      if ((i | ps[j]) > ps[j]) continue;
      int cnt = 0;
      int cur = i ^ ps[j];
      while (cur) {
        if (cur & 1) cnt++;
        cur >>= 1;
      }
      table[i][j] = cnt;
    }
  }
  int n, k;
  cin >> n >> k;
  for (int i= 0; i < n; i++) {
    string s; cin >> s;
    nums[i] = to_int(s);
  }
  memset(dp, -1, sizeof(dp));
  dp[n][0] = 0;
  for (int i = n-1; i >= 0; i--) {
    for (const auto& item : table[nums[i]]) {
      for (int t = 0; t+item.second <= k; t++) {
        if (dp[i+1][t] == -1) continue;
        dp[i][t+item.second] = max(dp[i][t+item.second], item.first);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (dp[i][k] == -1) {
      cout << "-1\n";
      return 0;
    }
    ret[i] = dp[i][k];
    k -= table[nums[i]][dp[i][k]];
  }
  assert(k == 0);
  for (int i = 0; i < n; i++) {
    cout << ret[i];
  }
  cout << '\n';










/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
