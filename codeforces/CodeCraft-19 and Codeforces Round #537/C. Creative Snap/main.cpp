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
map<int, int> table;
LL a, b;

int query(int x, int y) {
    auto it = table.upper_bound(y);
    if (it == table.begin()) return 0;
    it--;
    int val = it->second;
    it = table.lower_bound(x);
    if (it == table.begin()) return val;
    it--;
    return val - it->second;
}

LL solve(int x, int y) {
    int num = query(x, y);
    LL cost;
    if (num != 0) cost = b * num * (y-x+1);
    else cost = a;
    if (x == y || num == 0) {
        return cost;
    }
    int mid = (x + y) >> 1;
    cost = min(cost, solve(x, mid) + solve(mid+1, y));
    return cost;
}




int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n, k, pos;
    cin >> n >> k >> a >> b;
    for (int i = 0; i < k; i++) {
        cin >> pos;
        table[pos]++;
    }
    int pre = 0;
    for (auto it = table.begin(); it != table.end(); ++it) {
        it->second += pre;
        pre = it->second;
    }
    cout << solve(1, 1<<n) << endl;








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
