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
const int MAXV = 2e7 + 10;
bool np[MAXV];
LL cnt[MAXV], raw_cnt[MAXV], dp[MAXV];


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n; cin >> n;
    int ma = 0, val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        ma = max(ma, val);
        raw_cnt[val]++;
    }
    vi ps;
    for (int i = 2; i <= ma; i++) {
        if (np[i]) {
            continue;
        }
        ps.push_back(i);
        for (int j = i+i; j <= ma; j += i) {
            np[j] = true;
        }
    }
    LL ret = 0;
    for (int i = ma; i >= 1; i--) {
        dp[i] = i * raw_cnt[i];
        cnt[i] = raw_cnt[i];
        for (int p : ps) {
            LL ii = (LL)p * i;
            if (ii > ma) break;
            cnt[i] += cnt[ii];
        }
        for (int p : ps) {
            LL ii = (LL)p * i;
            if (ii > ma) break;
            dp[i] = max(dp[i], dp[ii] + (cnt[i] - cnt[ii]) * i);
        }
        ret = max(ret, dp[i]);
    }
    cout << ret << '\n';







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
