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
int cnt[10];
int cur[10];
LL fact[20], ret;

void solve(int k) {
    if (k == 10) {
        int tmp = 0;
        LL div = 1;
        for (int i = 0; i < 10; i++) {
            tmp += cur[i];
            div = fact[cur[i]] * div;
        }
        ret += fact[tmp] / div;
        if (cur[0] != 0) {
            div = div / fact[cur[0]] * fact[cur[0]-1];
            ret -= fact[tmp-1] / div;
        }
        return;
    }
    if (cnt[k] == 0) {
        solve(k+1);
        return;
    }
    for (int i = 1; i <= cnt[k]; i++) {
        cur[k] = i;
        solve(k+1);
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
    string s; cin >> s;
    for (char c : s) {
        cnt[c-'0']++;
    }
    fact[0] = 1;
    for (int i = 1; i <= 19; i++) {
        fact[i] = fact[i-1] * i;
    }
    solve(0);
    cout << ret << endl;




/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
