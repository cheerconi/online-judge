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
int nums[MAXN];

int solve(int n, int k, int p) {
    if (k == 0) return 0;
    if (p == -1) return -nums[n-k];
    int ret = INT_MAX;
    for (int i = 0; i < p; i++) {
        if (p-i > k) continue;
        if (p-i == k) {
            ret = min(ret, -nums[i]);
        } else {
            int tmp = k - (p-i);
            if (tmp+p-1 < n) {
                int tmp2 = 2*min(-nums[i], nums[tmp+p-1]) + max(-nums[i], nums[tmp+p-1]);
                ret = min(ret, tmp2);
            }
        }
    }
    if (p+k-1 < n) ret = min(ret, nums[p+k-1]);
    return ret;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    int p = -1;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (nums[i] == 0) {
            i--;
            n--;
            k--;
        }
        if (p == -1 && nums[i] > 0) p = i;
    }
    cout << solve(n, k, p) << endl;





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
