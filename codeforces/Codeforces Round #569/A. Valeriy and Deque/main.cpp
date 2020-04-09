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
deque<LL> nums;
LL table[MAXN];
pll ret[MAXN];





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n, q; cin >> n >> q;
    int idx = 0;
    LL val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        nums.push_back(val);
        if (val > nums[idx]) idx = i;
    }
    LL ma = nums[idx];
    int step = 1;
    for (int i = 0; i < idx; i++) {
        LL a = nums.front();
        nums.pop_front();
        LL b = nums.front();
        nums.pop_front();
        nums.push_back(min(a, b));
        nums.push_front(max(a, b));
        ret[step++] = {a, b};
    }
    for (int i = 0; i < n; i++) {
        table[i] = nums.front();
        nums.pop_front();
    }
    while (q--) {
        cin >> val;
        if (val < step) {
            cout << ret[val].first << ' ' << ret[val].second << '\n';
        } else {
            val -= step;
            val %= (n-1);
            cout << ma << ' ' << table[val+1] << '\n';
        }
    }








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
