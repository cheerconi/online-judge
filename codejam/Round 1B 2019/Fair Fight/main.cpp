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
typedef pair<LL, int> pli;
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
LL cnt[MAXN], nums[2][MAXN];

LL solve(int n, int k) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        LL tmp[2] = {0};
        for (int j = i; j < n; j++) {
            for (int y = 0; y < 2; y++) {
                tmp[y] = max(tmp[y], nums[y][j]);
            }
            if (abs(tmp[0] - tmp[1]) <= k) ret++;
        }
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
    int T; cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> nums[0][i];
        }
        for (int i = 0; i < n; i++) {
            cin >> nums[1][i];
        }
        cout << "Case #" << cs << ": " << solve(n, k) << endl;
    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
