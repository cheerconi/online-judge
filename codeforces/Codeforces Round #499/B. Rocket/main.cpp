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
const int MAXN = 100;
bool nums[MAXN];

int ask(LL num) {
    cout << num << endl;
    int ret;
    cin >> ret;
    if (ret == 0) exit(0);
    return ret;

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
    int n, m;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        int val = ask(m);
        if (val == 1) nums[i] = false;
        else nums[i] = true;
    }
    LL a = 1, b = m;
    int i = 0;
    while (a < b) {
        LL mid = (a+b) >> 1;
        int val = ask(mid);
        if (nums[i]) {
            if (val == 1) a = mid + 1;
            else b = mid - 1;
        }
        else {
            if (val == 1) b = mid - 1;
            else a = mid + 1;
        }
        i = (i+1) % n;
    }
    ask(a);
    return 0;


/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
