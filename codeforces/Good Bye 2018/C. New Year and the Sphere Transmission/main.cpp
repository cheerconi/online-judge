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
set<LL> ret;
map<LL, int> primes;
LL cur = 1, n;
void solve(map<LL, int>::iterator it) {
    LL tmp;
    if (it == primes.end()) {
        tmp = n / cur + 1;
        tmp = (2 + n) * tmp / 2 - (n+1);
        ret.insert(tmp);
        return;
    }
    auto it2 = it; it2++;
    solve(it2);
    tmp = 1;
    for (int i = 1; i <= it->second; i++) {
        tmp = tmp * it->first;
        cur = cur * tmp;
        solve(it2);
        cur = cur / tmp;
    }
}




int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    cin >> n;
    LL tmp = n;
    for (LL i = 2; i*i <= tmp; i++) {
        while (tmp % i == 0) {
            primes[i]++;
            tmp /= i;
        }
    }
    if (tmp != 1) primes[tmp]++;
    solve(primes.begin());
    for (auto num : ret) {
        cout << num;
        if (*ret.rbegin() == num) cout << endl;
        else cout << ' ';
    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
