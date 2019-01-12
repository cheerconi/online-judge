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
int x, y, u, v;

int gcd(int a, int b) {
    if (b == 0) return a;
    int k = -(a / b);
    int r = a % b;
    int new_u = x + k * u;
    int new_v = y + k * v;
    x = u;
    y = v;
    u = new_u;
    v = new_v;
    return gcd(b, r);
}





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int nn, n;
    cin >> n;
    nn = n;
    vector<int> ps;
    for (LL i = 2; i*i <= n; i++) {
        if (n % i != 0) continue;
        ps.push_back(i);
        if (ps.size() == 2) break;
        while (n % i == 0) {
            n /= i;
        }
    }
    if (n != 1 && ps.size() == 1) ps.push_back(n);
    if (ps.size() <= 1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    x = 1, y = 0;
    u = 0, v = 1;
    gcd(ps.back(), ps.front());
    if (x > 0) {
        x = nn/ps.back() - x;
        y = -y;
    } else {
        y = nn/ps.front() - y;
        x = -x;
    }
    vector<pii> ret;
    int b = nn / ps.back();
    while (x > 0) {
        if (x < b) {
            ret.emplace_back(x, b);
            x = 0;
        } else {
            ret.emplace_back(b-1, b);
            x -= b-1;
        }
    }
    b = nn / ps.front();
    while (y > 0) {
        if (y < b) {
            ret.emplace_back(y, b);
            y  = 0;
        } else {
            ret.emplace_back(b-1, b);
            y -= b-1;
        }
    }
    cout << ret.size() << endl;
    for (const auto& item : ret) {
        cout << item.first << ' ' << item.second << endl;
    }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
