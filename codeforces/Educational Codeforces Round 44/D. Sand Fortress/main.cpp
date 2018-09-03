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
LL bound;
bool fit(LL x, LL n, LL h) {
    if (x > bound) return false;
    LL tmp = (x+1)*x;
    if (tmp <= 0) return false;
    if (tmp % x != 0) return false;
    if (tmp / x != (x+1)) return false;
    if (tmp % 2 != 0) return false;
    tmp /= 2;
    if (tmp > n) return false;
    if (x <= h) return true;
    LL tmp2 = (h+x-1) * (x-h) / 2;
    if (tmp2 + tmp > n) return false;
    return true;
}

LL solve(LL n, LL h) {
    LL left = 1, right = 1e18;
    while (left < right) {
        LL mid = (left+right + 1) >> 1;
        if (!fit(mid, n, h)) {
            right = mid - 1;
        }
        else left = mid;
    }
    LL ret = left;
    n -= left*(left+1) / 2;
    if (left > h) {
        n -= (h+left-1)*(left-h) / 2;
        ret += left - h;
    }
    ret += n / left;
    n = n % left;
    if (n != 0) ret++;
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
    LL n, h;
    cin >> n >> h;
    bound = sqrt(LLONG_MAX);
    cout << solve(n, h) << endl;





/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
