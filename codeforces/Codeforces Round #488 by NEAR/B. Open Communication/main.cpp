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
set<int> ret[2];

int count(set<int> & a, set<int> & b) {
    vector<int> vs;
    for (auto it = a.begin(); it != a.end(); it++) {
        if (b.count(*it) == 1) vs.push_back(*it);
    }
    if (vs.size() == 0 || vs.size() == 2) return -1;
    return vs[0];
}
bool check(vector<set<int> >  & a, vector<set<int> > & b, int idx) {
    for (auto it1 = a.begin(); it1 != a.end(); it1++) {
        set<int> cand;
        for (auto it2 = b.begin(); it2 != b.end(); it2++) {
            int val = count(*it1, *it2);
            if (val == -1) continue;
            cand.insert(val);
        }
        if (cand.size() == 1) ret[idx].insert(*cand.begin());
        else if (cand.size() == 2) return false;
    }
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

    int n, m, a, b;
    cin >> n >> m;
    vector<set<int> > as, bs;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        set<int> tmp;
        tmp.insert(a);
        tmp.insert(b);
        as.push_back(tmp);
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        set<int> tmp;
        tmp.insert(a);
        tmp.insert(b);
        bs.push_back(tmp);
    }
    if (check(as, bs, 0) && check(bs, as, 1)) {
        int cnt = 0, val = -1;
        for (auto it = ret[0].begin(); it != ret[0].end(); it++) {
            if (ret[1].count(*it) == 1) {
                cnt++;
                val = *it;
            }
        }
        if (cnt == 1) cout << val << endl;
        else cout << 0 << endl;
    }
    else cout << -1 << endl;



/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
