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
typedef pair<char, int> pci;
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
string ret;
vector<pci> s;
int n;

LL compute(LL tmp, LL coeff, LL x) {
    LL res = tmp * coeff;
    if (res <= 0) return x;
    if (res % tmp != 0) return x;
    if (res / tmp != coeff) return x;
    if (res >= x) return x;
    return res;
}
void solve(int idx, LL k, LL x) {
    if (idx == n) {
        assert(x == 1);
        return;
    }
    if (s[idx].first == 'a') {
        for (int j = 0; j < s[idx].second; j++) {
            ret.push_back('a');
        }
        return solve(idx+1, k, x);
    }
    LL tmp = 1;
    for (int i = idx+1; i < n; i++) {
        if (s[i].first == '*') tmp = compute(tmp, (s[i].second * k)+1, x);
        if (tmp >= x) break;
    }
    for (int j = 0; j < s[idx].second * k; j++) {
        if (tmp >= x) break;
        ret.push_back('b');
        x -= tmp;
    }
    return solve(idx+1, k, x);
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
        ret.clear();
        s.clear();
        LL k, x;
        cin >> n >> k >> x;
        string tmp;
        cin >> tmp;
        for (char c : tmp) {
            if (s.empty() || s.back().first != c) {
                s.emplace_back(c, 1);
            } else {
                s.back().second++;
            }
        }
        n = s.size();
        solve(0, k,  x);
        cout << ret << '\n';
    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
