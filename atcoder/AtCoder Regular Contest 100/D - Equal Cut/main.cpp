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

const int MAXN = 2e5 + 10;
LL nums[MAXN], dp[MAXN];

pll solve(int i, int j) {
    if (i+1 == j) {
        LL ma, mi;
        ma = max(nums[i], nums[j]);
        mi = min(nums[i], nums[j]);
        return {mi, ma};
    }
    else {
        LL avg = (dp[j] - dp[i-1]) / 2;
        int p = lower_bound(dp+i, dp+j+1, avg+dp[i-1]) - dp;
        p--;
        p = max(p, i);
        LL a = dp[p] - dp[i-1];
        LL b = dp[j] - dp[p];
        p++;
        while (p < j) {
            LL tmpa = dp[p] - dp[i-1];
            LL tmpb = dp[j] - dp[p];
            if (abs(a-b) > abs(tmpa-tmpb)) {
                a = tmpa;
                b = tmpb;
            }
            if (tmpa > avg+1) break;
            p++;
        }
        if (a > b) swap(a, b);
        return {a, b};
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

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        dp[i] = dp[i-1] + nums[i];
    }
    LL ret = LLONG_MAX;
    for (int i = 3; i+1 <= n; i++) {
        auto a = solve(1, i-1);
        auto b = solve(i, n);
        ret = min(ret, max(a.second,b.second) - min(a.first, b.first));
    }
    cout << ret << endl;



/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
