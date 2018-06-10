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

int count(string & s) {
    int cnt = 0, mi = 0;
    for (char c : s) {
        if (c == '(') cnt++;
        else cnt--;
        mi = min(cnt, mi);
    }
    if (mi == 0  && cnt == 0) return 0;
    if (mi == 0 && cnt > 0) return cnt;
    if (mi < 0 && cnt == mi) return mi;
    return INT_MAX;
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

    map<int, int> table;

    int n; cin >> n;
    string s;
    while (n--) {
        cin >> s;
        table[count(s)]++;
    }
    LL tot = 0;
    for (auto it = table.begin(); it != table.end(); it++) {
        if (it->first > 0) break;
        if (it->first == 0) {
            tot += (LL)it->second * it->second;
        }
        else {
            tot += (LL)it->second * table[-it->first];
        }
    }
    cout << tot << endl;




/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
