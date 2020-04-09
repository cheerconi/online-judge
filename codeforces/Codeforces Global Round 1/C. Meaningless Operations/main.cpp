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


int solve(int val) {
    if (table.find(val) != table.end()) return table[val];
    int ret = 0;
    for (int i = 0; (1<<i) < val; i++) {
        if ((1<<i) & val) continue;
        ret += 1<<i;
    }
    assert(ret != 0);
    return val|ret;
}




int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    table[3] = 1;
    table[7] = 1;
    table[15] = 5;
    table[31] = 1;
    table[63] = 21;
    table[127] = 1;
    table[255] = 85;
    table[511] = 73;
    table[1023] = 341;
    table[2047] = 89;
    table[4095] = 1365;
    table[8191] = 1;
    table[16383] = 5461;
    table[32767] = 4681;
    table[65535] = 21845;
    table[131071] = 1;
    table[262143] = 87381;
    table[524287] = 1;
    table[1048575] = 349525;
    table[2097151] = 299593;
    table[4194303] = 1398101;
    table[8388607] = 178481;
    table[16777215] = 5592405;
    table[33554431] = 1082401;
    int q, val; cin >> q;
    while (q--) {
        cin >> val;
        cout << solve(val) << endl;
    }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
