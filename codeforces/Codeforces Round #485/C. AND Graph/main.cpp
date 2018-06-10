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
const int MAXN = 1<<23;
bool vis[MAXN];

bool solve(int val, int i, int cur, bool bound) {
    if (i == -1) {
        if (val == cur) return false;
        if (vis[cur]) return true;
        return false;
    }
    if ((val>>i) % 2 == 1) {
        return solve(val, i-1, cur, false);
    }
    if (solve(val, i-1, cur, bound)) return true;
    if (!bound) {
       if (solve(val, i-1, cur+(1<<i), bound)) return true;
    }
    return false;
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
    int n, m, val, ma;
    cin >> n >> m;
    ma = 0;
    for (int i = 0; i < m; i++) {
        cin >> val;
        vis[val] = true;
        ma = max(ma, val);
    }
    int cnt = 0;
    for (int i = 0; i <= ma; i++) {
        if (!vis[i]) continue;
        if (!solve(i, n-1, 0, true)) cnt++;
    }
    cout << cnt << endl;


/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
