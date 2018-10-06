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
const LD eps = 1e-9;
LL a[MAXN], b[MAXN];
int n;
bool solve(LD r) {
    LD x = -1e30, y = 1e30;
    for (int i = 0; i < n; i++) {
        LD tmp = 2*r*b[i] - b[i]*b[i];
        if (tmp < 0 && tmp < -eps) return false;
        if (tmp < 0) tmp = 0;
        tmp = std::sqrt(tmp);
        x = max(x, a[i]-tmp);
        y = min(y, a[i]+tmp);
        if (x > y && x-y > eps) return false;
    }
    return true;
}




int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    cin >> n;
    int cnt = 0;
    LD r1 = 0, r2 = 1e16;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (b[i] > 0) cnt++;
        else b[i] = -b[i];
        r1 = max(r1, (LD)b[i]/2);
    }
    if (0 < cnt && cnt < n) {
        cout << -1 << endl;
        return 0;
    }
    int tot = 0;
    while (r2 - r1 > eps && tot <= 500) {
        LD mid = (r1+r2) / 2;
        if (solve(mid)) r2 = mid;
        else r1 = mid;
        tot++;
    }
    cout << r1 << endl;






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
