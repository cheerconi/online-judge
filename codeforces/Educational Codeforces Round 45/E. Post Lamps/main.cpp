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

inline char get(void) {
    static char buf[100000], *S = buf, *T = buf;
    if (S == T) {
        T = (S = buf) + fread(buf, 1, 100000, stdin);
        if (S == T) return EOF;
    }
    return *S++;
}
inline void read(int &x) {
    static char c; x = 0; int sgn = 0;
    for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
    for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
    if (sgn) x = -x;
}

const int MAXN = 1e6 + 10;
int pos[MAXN], prices[MAXN];
LL ret = LLONG_MAX;

void solve(int k, int n) {
    int i = 0;
    LL cur = 0;
    while (i < n) {
        int j = pos[i];
        i = j + k;
        cur += prices[k];
        if (cur >= ret) return;
    }
    ret = cur;
}


/*-------------------------------------coding area end------------------------------------------*/
int main() {
    #ifdef LOCAL
        freopen("../test.txt", "r", stdin);
//        freopen("../output.txt", "w", stdout);
    #endif
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/

    int n, m, k, val;
    read(n); read(m); read(k);
    for (int i = 0; i < m; i++) {
        read(val);
        pos[val] = -1;
    }
    if (pos[0] == -1) {
        cout << -1;
        return 0;
    }
    int cur = 0, ma = 0;
    for (int i = 0; i <= n; i++) {
        if (pos[i] == 0) {
            cur = i;
        }
        pos[i] = cur;
        ma = max(i - cur, ma);
    }
    for (int i = 1; i <= k; i++) {
        read(prices[i]);
    }
    for (int i = ma+1; i <= k; i++) {
        solve(i, n);
    }
    if (ret == LLONG_MAX) ret = -1;
    cout << ret << endl;



/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
