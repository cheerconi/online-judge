#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <memory.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long double LD;
typedef long long LL;
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#ifdef LOCAL
#define DEBUG(x) { cerr << "# " << #x << ": " << x << endl;}
#else
#define DEBUG(x)
#endif
mt19937_64 mt(time(0));
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/
const int MAXN = 1e5 + 10;
int a[MAXN];
pll b[MAXN];
int tot[MAXN];
vector<int> st[MAXN];
int idx[MAXN];
int dp[3][MAXN];

bool check(const pll& x, LL power) {
    return power * x.second >= x.first;
}

bool cmp(int i, int j) {
    const pll& x = b[i];
    const pll& y = b[j];
    return x.first * y.second > x.second * y.first;
}

string solve(int n, int m) {
    string ret = string(tot[m-1], '0');
    if (n < m) return ret;
    sort(a, a+n, greater<int>());
    iota(idx, idx+m, 0);
    sort(idx, idx+m, cmp);
    dp[1][0] = 0;
    dp[2][m-1] = 0;
    for (int i = 0; i < m; i++) {
        dp[0][i] = check(b[idx[i]], a[i]);
        if (i-1 >= 0) dp[1][i] = check(b[idx[i-1]], a[i]);
        if (i+1 < m) dp[2][i] = check(b[idx[i+1]], a[i]);
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            dp[j][i] += dp[j][i-1];
        }
    }
    for (int ii = 0; ii < m; ii++) {
        int i = idx[ii];
        for (int val : st[i]) {
            pii item = b[i];
            item.first -= val;
            item.second--;
            int k = lower_bound(idx, idx+m, )

        }

    }

}


int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> tot[i];
            st[i].clear();
            LL sum = 0;
            for (int j = 0; j < tot[i]; j++) {
                int val; cin >> val;
                sum += val;
                st[i].push_back(val);
            }
            b[i] = make_pair(sum, tot[i]);
            if (i-1 >= 0) tot[i] += tot[i-1];
        }
        cout << solve(n , m) << endl;

    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
