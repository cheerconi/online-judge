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
const int MAXN = 1234;
int nums[MAXN][5];

bool solve(int a, int b, int n) {
  int onlya = 0;
  int onlyb = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i][a] == 0 && nums[i][b] == 0) return false;
    if (nums[i][a] == 0 && nums[i][b] != 0) onlyb++;
    if (nums[i][a] != 0 && nums[i][b] == 0) onlya++;
    if (onlya*2 > n) return false;
    if (onlyb*2 > n) return false;
  }
  return true;
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> nums[i][j];
      }
    }
    bool flag = false;
    for (int i = 0; i < 5 && !flag; i++) {
      for (int j = i+1; j < 5 && !flag; j++) {
        if (solve(i, j, n)) {
          flag = true;
        }
      }
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
