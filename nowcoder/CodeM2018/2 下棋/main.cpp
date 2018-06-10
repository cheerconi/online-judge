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
LL a[MAXN], b[MAXN];




/*-------------------------------------coding area end------------------------------------------*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
    #ifdef LOCAL
        freopen("../test.txt", "r", stdin);
//        freopen("../output.txt", "w", stdout);
    #endif
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    LL i = 1, j = n, ret = 0;
    for (int k = n; k >= 1; k--) {
        if (b[k] == 0) continue;
        while (i <= j && a[i] == 0) i++;
        while (j >= i && a[j] == 0) j--;
        if (j >= k) {
            if (a[j] >= b[k]) {
                ret += abs(j-k) * b[k];
                a[j] -= b[k];
                b[k] = 0;
            }
            else {
                ret += abs(j-k) * a[j];
                b[k] -= a[j];
                a[j] = 0;
                k++;
            }
        }
        else {
            if (a[i] >= b[k]) {
                ret += (i+k-2) * b[k];
                a[i] -= b[k];
                b[k] = 0;
            }
            else {
                ret += (i+k-2) * a[i];
                b[k] -= a[i];
                a[i] = 0;
                k++;
            }
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
