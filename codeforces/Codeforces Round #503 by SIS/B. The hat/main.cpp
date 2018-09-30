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
int n;

int ask(int a) {
    int ret1, ret2;
    cout << "? " << a << endl;
    cin >> ret1;
    a = (a-1 + n/2) % n + 1;
    cout << "? " << a << endl;
    cin >> ret2;
    if (ret1 == ret2) {
        cout << "! " << a << endl;
        exit(0);
    }
    if (ret1-ret2 > 0) return 1;
    return -1;

}





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
//    freopen("../test.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);
#endif
    cin >> n;
    if (n % 4 != 0) {
        cout << "! -1"<< endl;
        return 0;
    }
    int a = 1, b = 1 + n/2;
    LL ret1 = ask(a);
    LL ret2 = -ret1;
    while (a < b) {
        int mid = (a+b) >> 1;
        LL ret3 = ask(mid);
        if (ret1*ret3 > 0) {
            a = mid + 1;
        }
        else {
            b = mid - 1;
        }
    }
    cout << "! " << a << endl;







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
