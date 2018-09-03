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
const int MAXN = 300;
int mat[MAXN][MAXN];
int a1, a2, b1, b2, c1, c2, d1, d2;




/*-------------------------------------coding area end------------------------------------------*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
    #ifdef LOCAL
        freopen("../test.txt", "r", stdin);
//        freopen("../output.txt", "w", stdout);
    #endif
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/
    int val, n0 = INT_MAX, m0 = INT_MAX, n1 = INT_MIN, m1 = INT_MIN;
    for (int i = 0; i < 8; i++) {
        cin >> val;
        if (i % 2 == 0) {
            n0 = min(n0, val);
            n1 = max(n1, val);
        }
        else {
            m0 = min(m0, val);
            m1 = max(m1, val);
        }
    }
    set<int> xs, ys;
    for (int i = 0; i < 8; i++) {
        cin >> val;
        if (i % 2 == 0) xs.insert(val);
        else ys.insert(val);
    }
    assert(xs.size() == 3);
    assert(ys.size() == 3);
    auto it = xs.begin();
    int x0 = *it; it++;
    int x1 = *it; it++;
    int x2 = *it;
    auto it2 = ys.begin();
    int y0 = *it2; it2++;
    int y1 = *it2; it2++;
    int y2 = *it2;

    int bias = 120;
    for (int i = n0; i <= n1; i++) {
        for (int j = m0; j <= m1; j++) {
            mat[bias+i][bias+j]++;
        }
    }
    int delta = 0;
    for (int i = x0; i <= x2; i++) {
        mat[bias+i][bias+y1]++;
        for (int j = 1; j <= delta; j++) {
            mat[bias+i][bias+j+y1]++;
            mat[bias+i][bias-j+y1]++;
        }
        if (i < x1) delta++;
        else delta--;
    }
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            assert(mat[i][j] <= 2);
            if (mat[i][j] == 2) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;



/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
