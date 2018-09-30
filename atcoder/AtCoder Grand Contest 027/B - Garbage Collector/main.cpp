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
const int MAXN = 2e5 + 10;
LL nums[MAXN];

LL solve(int n, LL x, int k) {
    int i = n-1;
    LL ret = 0, cnt = 1;
    while (i >= 0) {
        for (int j = 0; j < k && i >= 0; j++, i--) {
            if (cnt == 1) ret += nums[i];
            ret += x;
            int tmp = i - k;
            if (tmp >= 0) {
                ret += (nums[i]-nums[tmp]) * (cnt+1) * (cnt+1);
            } else {
                ret += nums[i] * (cnt+1) * (cnt+1) + x;
            }
        }
        cnt++;
    }
    return ret;

}



int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    LL n, x; cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    LL ra = solve(n, x, 1), rb = solve(n, x, n);
    LL a = 1, b = n;
    while (b-a > 20) {
        LL c = a + (b-a)/3;
        LL d = a + (b-a)/3*2;
        LL rc = solve(n, x, c);
        LL rd = solve(n, x, d);
        if (rc >= rd && rb >= rd) {
            a = c;
            ra = rc;
        }
        else if (ra >= rc && rd >= rc) {
            b = d;
            rb = rd;
        }
        else if (ra <= rc) {
            b = c;
            rb = rc;
        }
        else {
            a = d;
            ra = rd;
        }
    }
    LL ret = ra;
    for (int i = a+1; i <= b; i++) {
        ret = min(ret, solve(n, x, i));
    }
    cout << ret << endl;





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
