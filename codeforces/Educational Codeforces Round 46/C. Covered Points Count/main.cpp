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
LL nums[MAXN*3];
LL p[2][MAXN], ret[MAXN];



/*-------------------------------------coding area end------------------------------------------*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
    #ifdef LOCAL
//        freopen("../test.txt", "r", stdin);
//        freopen("../output.txt", "w", stdout);
    #endif
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/

    int n; cin >> n;
    vector<LL> ps;
    for (int i = 0; i < n; i++) {
        cin >> p[0][i] >> p[1][i];
        ps.push_back(p[0][i]);
        ps.push_back(p[1][i]);
        ps.push_back(p[1][i]+1);
    }
    sort(ps.begin(), ps.end());
    ps.resize(unique(ps.begin(),ps.end())-ps.begin());
    int a;
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(ps.begin(), ps.end(), p[0][i]) - ps.begin();
        nums[idx]++;
        idx = lower_bound(ps.begin(), ps.end(), p[1][i]) - ps.begin();
        nums[idx+1]--;
    }
    for (int i = 1; i+1 < ps.size(); i++) {
        nums[i] += nums[i-1];
    }
    for (int i = 0; i+1 < ps.size(); i++) {
        ret[nums[i]] += ps[i+1] - ps[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << ret[i];
        if (i == n) cout << endl;
        else cout << ' ';
    }




/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
