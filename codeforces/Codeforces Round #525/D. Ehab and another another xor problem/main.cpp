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
int a, b;

int query(int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    int val;
    cin >> val;
    return val;
}

void solve_equal(int i) {
    if (i == -1) return;
    int val = query(a+(1<<i), b);
    assert(val != 0);
    if (val == -1) {
        a += 1<<i;
        b += 1<<i;
    }
    solve_equal(i-1);
}

void solve(int i, int val) {
    if (val == 0) {
        solve_equal(i);
        return;
    }
    if (i == 0) {
        if (val > 0) a += 1;
        else b += 1;
        return;
    }
    int tmp, tmp2;
    if (val > 0) {
        tmp = query(a, b + (1<<i));
        if (tmp == 0) {
            a += 1<<i;
            solve_equal(i-1);
            return;
        }
        if (tmp > 0) { // a[i] is 1
            tmp2 = query(a + (1<<i), b);
            assert(tmp2 != 0);
            a += 1<<i;
            if (tmp2 < 0) b += 1<<i;
            solve(i-1, 1);
        }
        else { // b[i] is 0
            tmp2 = query(a + (1<<i), b);
            assert(tmp2 != 0);
            if (tmp2 < 0) a += 1<<i;
            solve(i-1, tmp2);
        }
    } else {
        tmp = query(a+ (1<<i), b);
        if (tmp == 0) {
            b += 1<<i;
            solve_equal(i-1);
            return;
        }
        if (tmp > 0) { // a[i] is 0
            tmp2 = query(a, b + (1<<i));
            assert(tmp2 != 0);
            if (tmp2 > 0) b += 1<<i;
            solve(i-1, tmp2);
        }
        else { // b[i] is 1
            tmp2 = query(a, b + (1<<i));
            assert(tmp2 != 0);
            b += 1<<i;
            if (tmp2 > 0) a += 1<<i;
            solve(i-1, -1);
        }

    }


}





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int val = query(0, 0);
    solve(29, val);
    cout << "! " << a << ' ' << b << endl;




/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
