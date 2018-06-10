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
string sb, ret;
int cnt[10];

bool solve(int i, bool bound) {
    if (i == sb.size()) return true;
    int j;
    if (!bound) {
        for (j = 9; j >= 0; j--) {
            if (cnt[j] != 0) {
                ret.push_back(j+'0');
                cnt[j]--;
                return solve(i+1, false);
            }
        }
    }
    for (j = sb[i]-'0'; j >= 0; j--) {
        if (cnt[j] == 0) continue;
        cnt[j]--;
        ret.push_back(j+'0');
        if (solve(i+1, j==sb[i]-'0')) return true;
        cnt[j]++;
        ret.pop_back();
    }
    return false;

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
    int a, b;
    cin >> a >> b;
    sb = to_string(b);
    string tmp = to_string(a);
    for (char c : tmp) cnt[c-'0']++;
    if (tmp.size() > sb.size()) {
        cout << -1 << endl;
        return 0;
    }
    if (tmp.size() < sb.size()) {
        sort(tmp.begin(), tmp.end(), greater<char>());
        cout << tmp << endl;
        return 0;
    }
    if (solve(0, true) && ret[0] != '0') {
        cout << ret << endl;
    }
    else cout << -1 << endl;






/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
