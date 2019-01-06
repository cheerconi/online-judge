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
constexpr int MAXN = 1e5 + 10;
constexpr int MAXV = 7001;
bitset<MAXV> data[MAXN], coeff[MAXV], unit[MAXV];
bool mu[MAXV], np[MAXV];
vector<int> ps;

void init() {
    mu[1] = true;
    for (LL i = 2; i < MAXV; i++) {
        if (!np[i]) {
            ps.push_back(i);
            mu[i] = true;
        }
        for (int p : ps) {
            if (i*p >= MAXV || i % p == 0) break;
            mu[i*p] = mu[i];
        }
        if (np[i]) continue;
        for (LL j = i*i; j < MAXV; j += i) {
            np[j] = true;
        }
    }
    for (LL i = 1; i < MAXV; i++) {
        for (LL j = i; j < MAXV; j += i) {
            unit[j].flip(i);
        }
    }
    for (LL i = 1; i < MAXV; i++) {
        for (LL j = 1; j*i < MAXV; j++) {
            if (mu[j]) {
                coeff[i].flip(i*j);
            }

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
    init();
    int n, q, cmd, x, y, z;
    cin >> n >> q;
    while (q--) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> x >> y;
            data[x] = unit[y];
        } else if (cmd == 2) {
            cin >> x >> y >> z;
            data[x] = data[y] ^ data[z];
        } else if (cmd ==3) {
            cin >> x >> y >> z;
            data[x] = data[y] & data[z];
        } else {
            cin >> x >> y;
            auto tmp = data[x] & coeff[y];
            cout <<((int)tmp.count() % 2);
        }
    }
    cout << endl;






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
