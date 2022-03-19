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
const int MAXN = 5000 + 10;
int nums[MAXN];
LL dp[MAXN], ret[MAXN];


int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int T; cin >> T;
    while (T--) {
        LL n, val; cin >> n >> val;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            dp[i+1] = LLONG_MIN;
        }
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            LL cur = 0;
            for (int j = i; j < n; j++) {
                cur += nums[j];
                dp[j-i+1] = max(dp[j-i+1], cur);
            }
        }
        for (int i = n-1; i >= 0; i--) {
            dp[i] = max(dp[i], dp[i+1]);
        }
        LL tmp = dp[0];
        ret[0] = tmp;
        for (int i = 1; i <= n; i++) {
            tmp = max(tmp, dp[i] + val * i);
            ret[i] = tmp;
        }
        for (int i = 0; i <= n; i++) {
            cout << ret[i];
            if (i == n) cout << '\n';
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
