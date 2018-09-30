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
const int MAXN = 55;
LL nums[MAXN];

bool solve(LL val, int n, int k, int i) {
    if (n-i < k) return false;
    if (k == 0) {
        if (i == n) return true;
        return false;
    }
    if (i == n) return false;
    LL cur = 0;
    for (int j = i; n-j >= k-1; j++) {
        cur += nums[j];
        if ((cur&val) != val) continue;
        if (solve(val, n, k-1, j+1)) return true;
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
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    LL a = 0, b = 1LL<<60;
    while (a < b) {
        LL mid = (a+b + 1) >> 1;
        if (solve(mid, n, k, 0)) {
            a = mid;
        }
        else b = mid - 1;
    }
    cout << a << endl;






/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
