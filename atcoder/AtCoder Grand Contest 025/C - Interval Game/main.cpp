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
pii x[MAXN], y[MAXN], nums[MAXN];
bool vis[MAXN];

LL solve(bool lft, int n) {
    memset(vis, false, sizeof(vis));
    LL ret = 0, cur = 0;
    int i = 0, j = n-1;
    for (int k = 0; k < n; k++) {
        if (lft) {
            while (i < n && vis[x[i].second]) i++;
            vis[x[i].second] = true;
            if (nums[x[i].second].first <= cur && cur <= nums[x[i].second].second) continue;
            ret += abs(cur - x[i].first);
            cur = x[i].first;
        }
        else {
            while (j >= 0 && vis[y[j].second]) j--;
            vis[y[j].second] = true;
            if (nums[y[j].second].first <= cur && cur <= nums[y[j].second].second) continue;
            ret += abs(cur - y[j].first);
            cur = y[j].first;
        }
        lft = !lft;
    }
    ret += abs(cur);
    return ret;

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
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        x[i] = {b, i};
        y[i] = {a, i};
        nums[i] = {a, b};
    }
    sort(x, x+n);
    sort(y, y+n);
    LL ret = max(solve(true, n), solve(false, n));
    cout << ret << endl;






/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
