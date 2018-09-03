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
const int MAXN = 700 + 10;
bool mat[MAXN][MAXN];
int dp[MAXN][MAXN];
int nums[MAXN];

LL gcd(LL x, LL y) {
    if (y > x) swap(x, y);
    if (y == 0) return x;
    return gcd(y, x%y);
}

int solve(int x, int y) {
    if (dp[x][y] != 0) return dp[x][y];
    if (abs(x-y) == 1) {
        if (mat[x][y]) dp[x][y] = 1;
        else dp[x][y] = -1;
        return dp[x][y];
    }
    dp[x][y] = -1;
    if (x < y) {
        for (int i = x+1; i <= y && dp[x][y] != 1; i++) {
            if (!mat[i][x]) continue;
            if (solve(i, x+1)==1 && solve(i, y)==1) {
                dp[x][y] = 1;
            }
        }
    } else {
        for (int i = x-1; i >= y && dp[x][y] != 1; i--) {
            if (!mat[i][x]) continue;
            if (solve(i, y)==1 && solve(i, x-1)==1) {
                dp[x][y] = 1;
            }
        }
    }
    return dp[x][y];
}




int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n; cin >>n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        dp[i][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            LL tmp = gcd(nums[i], nums[j]);
            if (tmp > 1) {
                mat[i][j] = true;
                mat[j][i] = true;
            }
        }
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (solve(i, 0) == 1 && solve(i, n - 1) == 1) {
            flag = true;
            break;
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
