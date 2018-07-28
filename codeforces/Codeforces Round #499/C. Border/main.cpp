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
bool used[MAXN];
LL gcd(LL a, LL b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(a, b % a);

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

    LL n, k, cur = 0, val;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> val;
        val %= k;
        cur = gcd(cur, val);
    }
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        if (!used[i*cur%k]) cnt++;
        used[i*cur%k] = true;
    }
    cout << cnt << endl;
    for (int i = 0; i < k; i++) {
        if (used[i]) {
            cout << i;
            cnt--;
            if (cnt == 0) break;
            cout << ' ';
        }
    }
    cout << endl;




/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
