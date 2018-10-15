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
int a[MAXN], b[MAXN];





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n; cin >> n;
    LL ret = 0, tmp = 0;
    vector<pii> nums;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        nums.emplace_back(a[i], i*2);
        nums.emplace_back(b[i], i*2+1);
        ret += a[i];
        tmp += b[i];
    }
    ret = min(ret, tmp);
    sort(nums.begin(), nums.end());
    set<pii> table;
    tmp = 0;
    for (int i = 0; i < n - 2; i++) {
        table.insert(nums[i]);
        tmp += nums[i].first;
    }
    for (int i = 0; i < n; i++) {
        LL tmp1 = tmp;
        int cnt = 0;
        if (table.find(make_pair(a[i], i*2)) != table.end()) cnt++;
        if (table.find(make_pair(b[i], i*2+1)) != table.end()) cnt++;
        if (cnt == 2) {
            tmp1 += nums[n-2].first + nums[n-1].first;
        } else if (cnt == 0) {
            tmp1 += a[i] + b[i];
        } else {
            if (table.find(make_pair(a[i], i*2)) != table.end()) tmp1 += b[i];
            else tmp1 += a[i];
            if (nums[n-2] != make_pair(a[i], i*2) && nums[n-2] != make_pair(b[i], i*2+1)) {
                tmp1 += nums[n-2].first;
            } else {
                tmp1 += nums[n-1].first;
            }
        }
        ret = min(ret, tmp1);
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
