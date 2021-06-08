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
bool used[MAXN];
int nums[2][MAXN];
pii idx[MAXN * 2];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    fill(used, used+m, false);
    for (int i = 0; i < m; i++) {
      cin >> nums[0][i] >> nums[1][i];
      idx[2*i] = {0, i};
      idx[2*i+1] = {1, i};
    }
    sort(idx, idx+2*m, [](const pii& a, const pii& b){
      return make_pair(nums[a.first][a.second], 1 - a.first) > make_pair(nums[b.first][b.second], 1 - b.first);
    });
    LL ret = 0, cur = 0;
    for (int i = 0; i < 2*m && n > 0; i++) {
      const auto& item = idx[i];
      if (item.first == 0) {
        cur += nums[item.first][item.second];
        used[item.second] = true;
        n--;
        continue;
      }
      if (used[item.second]) {
        cur += (LL)nums[item.first][item.second] * n;
        break;
      }
      ret = max(ret, cur + (LL)nums[item.first][item.second] * (n-1) + nums[0][item.second]);
    }
    cout << max(ret,  cur) << endl;
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
