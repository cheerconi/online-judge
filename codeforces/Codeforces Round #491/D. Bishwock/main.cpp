#include <iostream>
#include <climits>
#include <memory.h>
#include <random>
#include <ctime>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
#ifdef LOCAL
    #define DEBUG(x) { cerr << "# " << #x << ": " << x << endl;}
#else
    #define DEBUG(x)
#endif
mt19937_64 mt(time(0));
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/
string mat[2];
int dp[4][200];

void solve(int a, int b, int c, int d, int i) {
    dp[c*2+d][i+1] = max(dp[a*2+b][i], dp[c*2+d][i+1]);
    if (dp[a*2+b][i] == -1) return;
    if (a == 0 && c == 0 && b == 0) {
        dp[2+d][i+1] = max(dp[a*2+b][i]+1, dp[2+d][i+1]);
    }
    if (a == 0 && c == 0 && d == 0) {
        dp[3][i+1] = max(dp[a*2+b][i]+1, dp[3][i+1]);
    }
    if (a == 0 && b == 0 && d == 0) {
        dp[c*2+1][i+1] = max(dp[a*2+b][i]+1, dp[c*2+1][i+1]);
    }
    if (b == 0 && c == 0 && d == 0) {
        dp[3][i+1] = max(dp[a*2+b][i]+1, dp[3][i+1]);
    }

}



/*-------------------------------------coding area end------------------------------------------*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
    #ifdef LOCAL
        freopen("../test.txt", "r", stdin);
//        freopen("../output.txt", "w", stdout);
    #endif
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/

    cin >> mat[0] >> mat[1];
    int n = mat[0].size();
    memset(dp, -1, sizeof(dp));
    dp[3][0] = 0;
    for (int i = 0; i < n; i++) {
        if (mat[0][i] == 'X') mat[0][i] = '1';
        if (mat[1][i] == 'X') mat[1][i] = '1';
        for (int a = 0; a <= 1; a++) {
            for (int b = 0; b <= 1; b++) {
                solve(a, b, mat[0][i]-'0', mat[1][i]-'0', i);
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        ret = max(dp[i][n], ret);
    }
    cout << ret << endl;



/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
