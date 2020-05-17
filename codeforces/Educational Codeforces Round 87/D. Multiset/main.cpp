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
const int M = 1000;
int cnt[M][M];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, q, val; cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> val;
    val--;
    cnt[val / M][val % M]++;
  }
  for (int i = 0; i < M; i++) {
    for (int j = 1; j < M; j++) {
      cnt[i][j] += cnt[i][j-1];
    }
  }
  while (q--) {
    cin >> val;
    if (val > 0) {
      val--;
      for (int i = val/M, j = val%M; j < M; j++) {
        cnt[i][j]++;
      }
    } else {
      val = -val;
      int i = 0;
      int cur = 0;
      while (i < M && cnt[i][M-1] + cur < val) {
        cur += cnt[i][M-1];
        i++;
      }
      int j = 0;
      while (j < M && cur+cnt[i][j] < val) j++;
      while (j < M) {
        cnt[i][j]--;
        j++;
      }
    }
  }
  int ret = 0;
  for (int i = 0; i < M && ret == 0; i++) {
    for (int j = 0; j < M && ret == 0; j++) {
      if (cnt[i][j] != 0) {
        ret = i*M + j + 1;
      }
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
