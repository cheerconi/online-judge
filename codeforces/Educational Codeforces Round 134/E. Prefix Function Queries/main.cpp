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
const int MAXN = 1e6 + 20;
int pi[MAXN];
int dp[26][MAXN];
int n;
string s;

int find(int j, char c) {
    int x = j;
    int ret = -1;
    while (x > 0 && s[x] != c) {
        if (x < n && dp[c-'a'][x] != -1) {
            ret = dp[c-'a'][x];
            break;
        }
        x = pi[x-1];
    }
    if (ret == -1) {
        ret = x;
        if (s[x] == c) ret++;
    }
    x = j;
    while (x > 0 && s[x] != c) {
        if (x < n) {
            if (dp[c-'a'][x] != -1) break;
            dp[c-'a'][x] = ret;
        }
        x = pi[x-1];
    }
    return ret;
}

void solve() {
    for (int i = n; i < s.size(); i++) {
        pi[i] = find(pi[i-1], s[i]);
    }
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    cin >> s;
    n = s.size();
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i < n; i++) {
        pi[i] = find(pi[i-1], s[i]);
    }
    int q; cin >> q;
    while (q--) {
        string t; cin >> t;
        for (char c : t) {
            s.push_back(c);
        }
        solve();
        for (int i = n; i < s.size(); i++) {
            cout << pi[i];
            if (i+1 == s.size()) cout << '\n';
            else cout << ' ';
        }
        while (s.size() != n) s.pop_back();
    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
