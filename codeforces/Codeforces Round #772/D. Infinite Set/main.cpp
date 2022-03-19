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
const int MAXN = 2e5 + 10;
const int mod = 1e9 + 7;
int nums[MAXN];
LL dp[MAXN];

LL solve(int n, int p) {
    set<int> table;
    LL ret = 0;
    for (int i = 0; i < n; i++) {
        vector<int> bs;
        int val = nums[i];
        bool done = false;
        while (val > 1) {
            if (val % 2 == 1) val /= 2;
            else if (val % 4 == 0) val /= 4;
            else break;
            if (table.find(val) != table.end()) {
                done = true;
                break;
            }
        }
        if (done) {
            continue;
        }
        int cnt = 0;
        val = nums[i];
        while (val) {
            cnt++;
            val >>= 1;
        }
        if (p - cnt >= 0) ret = (ret + dp[p-cnt]) % mod;
        table.insert(nums[i]);
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
    int n, p; cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums+n);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= p; i++) {
        dp[i] =(dp[i-1] + dp[i-2]) % mod;
    }
    for (int i = 1; i <= p; i++) {
        dp[i] = (dp[i] + dp[i-1]) % mod;
    }
    cout << solve(n, p) << '\n';







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
