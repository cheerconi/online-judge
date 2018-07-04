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

set<pll> dp[49];

void insert(set<pll> & table, LL a, LL b) {
    if (table.empty()) {
        table.insert({a, b});
        return;
    }
    auto it = table.lower_bound({b,LLONG_MAX});
    while (it != table.begin()) {
        it--;
        if (it->second < a) break;
        a = min(it->first, a);
        b = max(it->second, b);
        if (it == table.begin()) {
            table.erase(it);
            break;
        }
        else {
            table.erase(it++);
        }
    }
    table.insert({a,b});


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

    LL n; cin >> n;
    for (int i = 0; i <= min(48LL, n); i++) {
        for (int j = 0; j <= 8 && i+j <= n; j++) {
            int tmp = i*9 + j*4;
            LL a = tmp / 49;
            LL b = n-i-j + tmp/49;
            insert(dp[tmp%49], a, b);
        }
    }
    LL ret = 0;
    for (int i = 0; i < 49; i++) {
        for (auto item : dp[i]) {
            ret += item.second - item.first + 1;
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
