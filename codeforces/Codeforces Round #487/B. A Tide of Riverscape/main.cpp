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

const int MAXN = 2000 + 10;
string data[MAXN];

bool solve(int m, int p) {
    for (int i = 0; i < p; i++) {
        int cnt[4] = {0};
        for (int j = 0; j < m && i < data[j].size(); j++) {
            cnt[3]++;
            if (data[j][i] == '0') cnt[0]++;
            else if (data[j][i] == '1') cnt[1]++;
            else cnt[2]++;
        }
        if (cnt[3] == 1) continue;
        if (cnt[0] > 0 && cnt[1] > 0) return true;
        if (cnt[0] == cnt[3] || cnt[1] == cnt[3]) continue;
        int val = 0;
        if (cnt[1] == 0) val = 1;
        for (int j = 0; j < m && i < data[j].size(); j++) {
            if (data[j][i] == '.') {
                data[j][i] = val + '0';
                break;
            }
        }
        val = 1 - val;
        for (int j = 0; j < m && i < data[j].size(); j++) {
            if (data[j][i] == '.') {
                data[j][i] = val + '0';
                break;
            }
        }
        return true;
    }
    return false;
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

    int n, p;
    cin >> n >> p;
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++) {
        data[i/p].push_back(s[i]);
    }
    int m = n / p;
    if (n % p) m++;

    if (!solve(m, p)) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < data[i].size(); j++) {
            if (data[i][j] == '.') cout << '0';
            else cout << data[i][j];
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
