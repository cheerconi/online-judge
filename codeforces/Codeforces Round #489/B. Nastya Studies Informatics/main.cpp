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
map<LL, LL> table;
LL val, a, b, ret, x, y;

void solve(map<LL, LL>::iterator it, LL cur) {
    if (it == table.end()) {
        LL tmp = val / cur * x;
        LL tmp2 = cur * x;
        if (a <= tmp && tmp <= b && a <= tmp2 && tmp2 <= b) {
            ret++;
        }
        return;
    }
    auto it2 = it;
    it2++;
    solve(it2, cur);
    solve(it2, cur*it->second);
}








/*-------------------------------------coding area end------------------------------------------*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
    #ifdef LOCAL
//        freopen("../test.txt", "r", stdin);
//        freopen("../output.txt", "w", stdout);
    #endif
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/
    cin >> a >> b >> x >> y;
    if (y % x != 0) {
        cout << 0 << endl;
        return 0;
    }
    if (y == x) {
        if (a <= x && x <= b) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    val = y / x;
    for (LL i = 2; i*i <= val; i++) {
        while(val % i == 0) {
            val /= i;
            if (table[i] == 0) table[i] = 1;
            table[i] = table[i]*i;
        }
    }
    if (val != 1) {
        if (table[val] == 0) table[val] = 1;
        table[val] = table[val] * val;
    }
    val = y / x;

    solve(table.begin(), 1);
    cout << ret << endl;








/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
