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
typedef pair<char, int> pci;
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
string mat[MAXN];
pci dp[MAXN][MAXN];
char tmp;
int n;

void solve(int k,  int x, int y) {
    if (x == n || y == n) return;
    if (mat[x][y] != 'a' && k != 0) {
        dp[x][y] = min(dp[x][y], make_pair('a', k+1));
    } else {
        dp[x][y] = min(dp[x][y], make_pair(mat[x][y], k));
    }
    tmp = min(tmp, dp[x][y].first);
}




int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = make_pair('z', INT_MAX);
        }
    }
    string ret;

    if (k != 0 && mat[0][0] != 'a') dp[0][0] = make_pair('a', -(k-1));
    else dp[0][0] = make_pair(mat[0][0], -k);
    ret.push_back(dp[0][0].first);

    for (int len = 0; len <= 2*n-3; len++) {
        tmp = 'z';
        for (int i = max(0, len-n+1); i <= min(len, n-1); i++) {
            int j = len - i;
            if (dp[i][j].second == INT_MAX || dp[i][j].first != ret.back()) continue;
            solve(dp[i][j].second, i+1, j);
            solve(dp[i][j].second, i, j+1);
        }
        ret.push_back(tmp);
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
