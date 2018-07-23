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

LL gcd(LL a, LL b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

bool solve(LL r, LL b, LL c, LL d) {
    if (r != 0 && r < b - c) return false;
    if (d == 0) return true;
    if (d <= b-c-1) return false;
    LL tmp = gcd(b, d);
    if (tmp <= b-c-1) return false;
    r = r % tmp;
    LL x = 1 - r;
    if (x < 0) x += b;
    LL y = b-c-1 - r;
    if (y < 0) y += b;
    x = x / tmp;
    y = y / tmp;
    if (x != y) return false;
    return true;
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
    LL a, b, c, d;
    int T; cin >> T;
    while(T--) {
        cin >> a >> b >> c >> d;
        if (b > min(a, d)) {
            cout << "No\n";
            continue;
        }
        if (c+1 >= b) {
            cout << "Yes\n";
            continue;
        }
        a = (a-c) % b + c;
        if (a != c) a -= b;
        a = a - c;
        if (a < 0) a += b;
        if (solve(a, b, c, d % b)) cout << "Yes\n";
        else cout << "No\n";
    }



/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
