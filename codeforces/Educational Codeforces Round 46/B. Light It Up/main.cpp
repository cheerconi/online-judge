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
const int MAXN = 1e5 + 10;
int nums[MAXN];
LL dp[2][MAXN];



/*-------------------------------------coding area end------------------------------------------*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
    #ifdef LOCAL
//        freopen("../test.txt", "r", stdin);
//        freopen("../output.txt", "w", stdout);
    #endif
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/


    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    nums[n+1] = m;
    int idx = 0;
    if (n % 2 == 1)  idx = 1;
    for (int i = n; i >= 0; i--) {
        dp[idx][i] = nums[i+1] - nums[i];
        dp[0][i] += dp[0][i+1];
        dp[1][i] += dp[1][i+1];
        idx = 1 - idx;
    }
    LL ret = dp[0][0];
    idx = 0;
    LL cur = 0;
    for (int i = 0; i <= n; i++, idx = 1 - idx) {
        if (idx == 0) cur += nums[i+1] - nums[i];
        if (nums[i]+1 == nums[i+1]) continue;
        if (idx == 0) {
            ret = max(ret, cur-1+dp[1][i+1]);
        }
        else {
            ret = max(ret, cur+nums[i+1]-nums[i]-1+dp[1][i+1]);
        }
    }
    cout << ret << endl;





/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
