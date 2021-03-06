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
const int MAXN = 5e5 + 10;
int nums[MAXN], cnt[MAXN];




/*-------------------------------------coding area end------------------------------------------*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
    #ifdef LOCAL
        freopen("../test.txt", "r", stdin);
//        freopen("../output.txt", "w", stdout);
    #endif
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/
    int n, k, d, a, b;
    cin >> n >> k >> d;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums+n);
    for (int i = n-1; i >= 0; i--) {
        a = i+k;
        b = upper_bound(nums, nums+n, nums[i]+d) - nums;
        if (a <= b) {
            if (b == n || cnt[a] - cnt[b+1] > 0) cnt[i]++;
        }
        cnt[i] += cnt[i+1];
    }
    if (cnt[0]-cnt[1] > 0) cout << "YES" << endl;
    else cout << "NO" << endl;




/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
