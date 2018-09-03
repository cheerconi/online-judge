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
LL nums[MAXN], dist[MAXN];
int n;

LL solve(int i, int j) {
    if (i > j) swap(i, j);
    LL ret = dist[j-1] - dist[i-1];
    LL tmp = dist[n] - dist[j-1] + dist[i-1];
    ret = min(ret, tmp);
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
    int s;
    cin >> n >> s;
    set<int> table;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        if(i != s) table.insert(i);
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = dist[i-1] + nums[i];
    }
    LL ret = 0;
    while (!table.empty()) {
        auto it = table.lower_bound(s);
        int a, b;
        if (it == table.end()) {
            it--;
            a = *it;
            b = *table.begin();
        }
        else if (it == table.begin()) {
            a = *it;
            b = *table.rbegin();
        }
        else {
            a = *it;
            it--;
            b = *it;
        }
        LL reta = solve(s, a);
        LL retb = solve(s, b);
        ret += min(reta, retb);
        if (reta < retb || (reta==retb && a < b)) {
            table.erase(a);
            s = a;
        }
        else {
            table.erase(b);
            s = b;

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
