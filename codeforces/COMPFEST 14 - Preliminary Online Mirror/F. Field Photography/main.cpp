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
const int MAXB = 30;
const int MAXM = (1<<20) + 10;
int a[MAXN], b[MAXN], tmp[MAXM];
int dp[MAXB];





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i <= 20; i++) {
        int mod = 1<<i;
        if (i != 0) {
            memset(tmp, 0, sizeof(tmp));
        }
        for (int j = 0; j < n; j++) {
            if (b[j]-a[j]+1 >= mod) {
                dp[i]++;
                continue;
            }
            int x = a[j] % mod;
            int y = x + b[j] - a[j];
            tmp[x]++;
            if (y < mod) {
                tmp[y+1]--;
                continue;
            }
            tmp[mod+1]--;
            tmp[0]++;
            tmp[y-mod+1]--;
        }
        int cur = 0, ma = 0;
        for (int k = 0; k <= mod; k++) {
            cur += tmp[k];
            ma = max(ma, cur);
            if (ma+dp[i] == n) break;
        }
        dp[i] += ma;
    }
    for (int i = 21; i < MAXB; i++) {
        int mod = 1<<i;
        map<int, int> cnt;
        cnt[0] = 0;
        cnt[mod+1] = 0;
        for (int j = 0; j < n; j++) {
            if (b[j]-a[j]+1 >= mod) {
                dp[i]++;
                continue;
            }
            int x = a[j] % mod;
            int y = x + b[j] - a[j];
            cnt[x]++;
            if (y < mod) {
                cnt[y+1]--;
                continue;
            }
            cnt.rbegin()->second--;
            cnt.begin()->second++;
            cnt[y-mod+1]--;
        }
        int cur = 0, ma = 0;
        for (const auto& [_, val] : cnt) {
            cur += val;
            ma = max(ma, cur);
            if (ma+dp[i] == n) break;
        }
        dp[i] += ma;
    }
    int q, mask; cin >> q;
    while (q--) {
        cin >> mask;
        int i = 0;
        while ((mask & (1<<i)) == 0) {
            i++;
        }
        cout << dp[i] << '\n';
    }







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */