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
const int MAXN = 100;
const int MAXM = 3e5 + 10;
int cnt[MAXN], tmp[MAXN], ma[MAXM], mi[MAXM];

void solve(int val) {
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < MAXN; i++) {
        if (i >= val) {
            tmp[i - val] += cnt[i];
        } else {
            if (i % 2 == val % 2) {
                tmp[0] += cnt[i];
            } else {
                tmp[1] += cnt[i];
            }
        }
    }
    for (int i = 0; i < MAXN; i++) {
        cnt[i] = tmp[i];
    }
}

int count(LL val) {
    int ret = 0;
    while (val) {
        if (val & 1) ret++;
        val >>= 1;
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
    LL n, val, ret = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        val = count(val);
        ma[i] = mi[i] = val;
        for (int j = 1; j < MAXN; j++) {
            if (i-j < 0) break;
            if (mi[i-j] <= val && val <= ma[i-j]) {
                if (mi[i-j] % 2 == val % 2) {
                    mi[i-j] = 0;
                } else {
                    mi[i-j] = 1;
                }
            }
            else if (val > ma[i-j]) {
                mi[i-j] = val - ma[i-j];
            } else {
                mi[i-j] = mi[i-j] - val;
            }
            ma[i-j] += val;
            if (mi[i-j] == 0) ret++;
        }
        solve(val);
        ret += cnt[0];
        if (i-MAXN+1 >= 0) cnt[mi[i-MAXN+1]]++;
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
