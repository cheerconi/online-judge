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
const int MAXN = 1e5 + 10;
int nums[MAXN];



/*-------------------------------------coding area end------------------------------------------*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
    #ifdef LOCAL
//        freopen("../test.txt", "r", stdin);
//        freopen("../output.txt", "w", stdout);
    #endif
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/
    int n, k, l;
    cin >> n >> k >> l;
    for (int i = 0; i < n*k; i++) {
        cin >> nums[i];
    }
    sort(nums, nums+n*k);

    int p = upper_bound(nums, nums+n*k, nums[0]+l) - nums;
    if (p < n) {
        cout << 0 << endl;
        return 0;
    }
    LL ret = 0;
    int i = 0;
    while (n > 0 && p-i-k >= n-1) {
        ret += nums[i];
        i += k;
        n--;
    }
    if (n > 0) {
        ret += nums[i];
        n--;
    }
    p--;
    while (n--) {
        ret += nums[p];
        p--;
    }
    cout << ret << endl;





/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
