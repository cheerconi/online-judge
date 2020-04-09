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
LL nums[MAXN], dp[2][MAXN];

void solve(int n) {
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += nums[i];
        dp[0][i] = sum;
        if (nums[i] == 0) {
            dp[0][i] = min(dp[0][i], dp[0][i-1] + 2);
        } else if (nums[i] % 2 == 0) {
            dp[0][i] = min(dp[0][i], dp[0][i-1]);
        } else {
            dp[0][i] = min(dp[0][i], dp[0][i-1] + 1);
        }
    }
    sum = 0;
    for (int i = n; i > 0; i--) {
        sum += nums[i];
        dp[1][i] = sum;
        if (nums[i] == 0) {
            dp[1][i] = min(dp[1][i], dp[1][i+1] + 2);
        } else if (nums[i] % 2 == 0) {
            dp[1][i] = min(dp[1][i], dp[1][i+1]);
        } else {
            dp[1][i] = min(dp[1][i], dp[1][i+1] + 1);
        }
    }
}



int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    solve(n);
    for (int i = 1; i <= n; i++) {
        if (nums[i] % 2 == 1) dp[0][i] = min(dp[0][i], dp[0][i-1]);
        else dp[0][i] = min(dp[0][i], dp[0][i-1]+1);
    }
    LL ret = LLONG_MAX;
    for (int i = 0; i <= n; i++) {
        ret = min(ret, dp[0][i] + dp[1][i+1]);
    }
    cout << ret << endl;







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
