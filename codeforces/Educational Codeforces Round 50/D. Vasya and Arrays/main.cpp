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
const int MAXN = 3e5 + 10;
LL a[MAXN], b[MAXN];





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int m; cin >> m;
    for (int i = 0; i < m; i++) cin >> b[i];
    int i = 0, j = 0;
    LL tota = 0, totb = 0;
    int cnt = 0;
    while (i < n && j < m) {
        if (tota > totb) {
            totb += b[j++];
        }
        else if (tota < totb) {
            tota += a[i++];
        }
        else if (tota != 0) {
            tota = 0;
            totb = 0;
            cnt++;
        }
        else {
            tota += a[i++];
            totb += b[j++];
        }
    }
    while (i < n) tota += a[i++];
    while (j < m) totb += b[j++];
    if (tota != 0) cnt++;
    if (tota == totb) {
        cout << cnt << endl;
    } else {
        cout << -1 << endl;
    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
