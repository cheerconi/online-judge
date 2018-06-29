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
const int mod = 1e9 + 7;
int n, k, nums[MAXN];

int count() {
    int tot = 0;
    map<int, int> table;
    for (int i = 0; i < n; i++) {
        if (i-k >= 0) {
            table[nums[i-k]]--;
            if (table[nums[i-k]] == 0) table.erase(nums[i-k]);
        }
        if (table.find(nums[i]) == table.end()) {
            if (table.size() == tot) tot++;
        }
        table[nums[i]]++;
    }
    return tot;
}

LL solve(LL tot) {
    LL ret = 1;
    map<int, int> table;
    LL cur = 0;
    for (int i = 0; i < n; i++) {
        if (i-k >= 0) {
            table[nums[i-k]]--;
            if (table[nums[i-k]] == 0) {
                table.erase(nums[i-k]);
                cur--;
            }
        }
        if (table.find(nums[i]) == table.end()) {
            ret = ret * (tot - cur) % mod;
            cur++;
        }
        table[nums[i]]++;
    }
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
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int tot = count();
    LL ret = solve(tot);
    cout << ret << endl;



/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
