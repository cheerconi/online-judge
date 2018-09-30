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
const int MAXN = 2e5 + 10;
LL inf = 1e8 * 2e5;
LL data[MAXN];
int nxt[MAXN];

void overflow(LL & a, LL b, LL c) {
    if (a == 0) return;
    if (a < 0 || a > inf) {
        a = 0;
        return;
    }
    if (a % b != 0 || a % c != 0) {
        a = 0;
        return;
    }
    if (a / b != c || a / c != b) {
        a = 0;
        return;
    }
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

    LL n, k;
    cin >> n >> k;
    inf = inf * k;
    for (int i = 1; i <= n; i++) {
        cin >> data[i];
    }
    int idx = n+1;
    for (int i = n; i >= 1; i--) {
        nxt[i] = idx;
        if (data[i] != 1) idx = i;
    }

    LL ret = 0;
    for (int i = 1; i <= n; i++) {
        LL p = data[i], s = data[i];
        if (p % s == 0 && p / s == k) ret++;
        for (int j = i+1; j <= n; j++) {
            if (data[j] == 1) {
                int jj = nxt[j];
                if (p % k == 0) {
                    LL tmp = p / k;
                    tmp -= s;
                    if (tmp >= 1 && jj - j >= tmp) ret++;
                }
                s += jj - j;
                j = jj;
            }
            if (j == n+1) break;
            LL pp = p * data[j];
            overflow(pp, p, data[j]);
            if (pp == 0) break;
            p = pp;
            s += data[j];
            if (p % s == 0 && p / s == k) ret++;
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
