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
const int MAXN = 20;
string s1, s2, a, b;
LL dp[MAXN][MAXN], ret;
void solve() {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int k = 0; k < s2.size(); k++) {
        for (int i = 0; i <= min((int)a.size(), k); i++) {
            int j = k - i;
            if (i < a.size() && s2[k] == a[i]) {
                dp[i+1][j] += dp[i][j];
            }
            if (j < b.size() && s2[k] == b[j]) {
                dp[i][j+1] += dp[i][j];
            }
        }
    }
    ret += dp[a.size()][b.size()];
}
void dfs(int i) {
    if (i == s1.size()) {
        solve();
        return;
    }
    a.push_back(s1[i]);
    dfs(i+1);
    a.pop_back();
    b.push_back(s1[i]);
    dfs(i+1);
    b.pop_back();
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
    int n; cin >> n;
    string s; cin >> s;
    s1 = s.substr(0, n);
    s2 = s.substr(n);
    reverse(s2.begin(), s2.end());
    dfs(0);
    cout << ret << endl;


/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
