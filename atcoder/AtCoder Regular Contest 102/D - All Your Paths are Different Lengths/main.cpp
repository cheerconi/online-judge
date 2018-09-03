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
struct Item{
    int a, b, c;
    Item(int _a, int _b, int _c) {
        a = _a;
        b = _b;
        c = _c;
    }
};
int n, base;
vector<Item> ret;
int solve(int& L) {
    int tmp = 0;
    while ((1<<tmp) <= L) {
        tmp++;
    }
    if (n == 0) {
        n = tmp;
        for (int i = 1; i+1 <= n; i++) {
            ret.emplace_back(i,i+1,0);
            ret.emplace_back(i,i+1, 1<<(i-1));
        }
    } else {
        ret.emplace_back(tmp, n, base);
    }
    L -= 1<<(tmp-1);
    base += 1<<(tmp-1);
}





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int L; cin >> L;
    while (L) {
        solve(L);
    }
    cout << n << ' ' << ret.size() << endl;
    for (auto item : ret) {
        cout << item.a << ' ' << item.b << ' ' << item.c << endl;
    }










/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
