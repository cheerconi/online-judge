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
const int mod = 1e9 + 7;
const int MAXN = 500 + 10;
pll dp[MAXN];

bool overlap(int a, int b, int len) {
    int a1 = a;
    int a2 = a+len-1;
    int b1 = b;
    int b2 = b+len-1;
    if (a2 < b1 || b2 < a1) return false;
    return true;
}

pll solve(const vi& idx, int len) {
    if (idx.empty()) return {0, 1};
    memset(dp, -1, sizeof(dp));
    dp[0] = {0, 1};
    dp[1] = {1, 1};
    for (int i = 1; i < idx.size(); i++) {
        int j = i;
        while (j >= 0 && overlap(idx[j], idx[i], len)) j--;
        if (j == -1) {
            dp[i+1] = {1, 1};
            continue;
        }
        for (int k = j; k >= 0; k--) {
            if (!overlap(idx[k], idx[j], len)) break;
            LL used = dp[k+1].first + 1;
            if (dp[i+1].first == -1) dp[i+1] = {used, 0};
            if (used == dp[i+1].first) {
                dp[i+1].second = (dp[i+1].second + dp[k+1].second) % mod;
            } else if (used < dp[i+1].first) {
                dp[i+1] = {used, dp[k+1].second};
            }
        }
    }
    LL used = idx.size();
    for (int i = 0; i < idx.size(); i++) {
        if (!overlap(idx[i], idx.back(), len)) continue;
        used = min(used, dp[i+1].first);
    }
    LL cnt = 0;
    for (int i = 0; i < idx.size(); i++) {
        if (!overlap(idx[i], idx.back(), len)) continue;
        if (used != dp[i+1].first) continue;
        cnt = (cnt + dp[i+1].second) % mod;
    }
    return {used, cnt};
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int q; cin >> q;
    while (q--) {
        string s, t; cin >> s >> t;
        vector<int> idx;
        for (int i = 0; i+t.size() <= s.size(); i++) {
            if (s.substr(i, t.size()) == t) idx.push_back(i);
        }
        pll ret = solve(idx, t.size());
        cout << ret.first << ' ' << ret.second << '\n';
    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
