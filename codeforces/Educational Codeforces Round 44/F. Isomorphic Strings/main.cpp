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
const int mod = 1e9 + 7;
LL hsh[MAXN][26], coeff[MAXN];

void build(string & s, LL base) {
    for (int i = 0; i < 26; i++) {
        hsh[0][i] = 1;
    }
    coeff[0] = 1;
    for (int i = 0; i < s.size(); i++) {
        coeff[i+1] = coeff[i] * base % mod;
        for (int j = 0; j < 26; j++) {
            hsh[i+1][j] = hsh[i][j];
            if (s[i]-'a' == j){
                hsh[i+1][j] += coeff[i+1];
                hsh[i+1][j] %= mod;
            }
        }
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
    int n, m, a, b, c;
    cin >> n >> m;
    string s; cin >> s;
    build(s, 1e9 + 9);
    while (m--) {
        cin >> a >> b >> c;
        if (a > b) swap(b, a);
        vector<int> dp[2];
        for (int i = 0; i < 26; i++) {
            LL tmp = (hsh[b+c-1][i] - hsh[b-1][i] + mod) % mod;
            dp[1].push_back(tmp);
            tmp = (hsh[a+c-1][i] - hsh[a-1][i] + mod) % mod;
            tmp = tmp * coeff[b-a] % mod;
            dp[0].push_back(tmp);
        }
        sort(dp[0].begin(), dp[0].end());
        sort(dp[1].begin(), dp[1].end());
        if (dp[0] == dp[1]) cout << "YES\n";
        else cout << "NO\n";
    }




/*-------------------------------------coding area end------------------------------------------*/

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */

