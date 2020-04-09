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
vector<LL> solve(LL a, LL b, LL m) {
    if (a == b) return {a};
    vector<pll> vs;
    vs.emplace_back(a, a);
    pll sum = {a, a};
    while (vs.back().first <= b) {
        vs.emplace_back(sum.first +1, sum.second + m);
        if (sum.first+1 <= b && b <= sum.second+m) break;
        sum.first += sum.first + 1;
        sum.second += sum.second + m;
    }
    vector<LL> ret;
    if (vs.back().first > b) return ret;
    int sz = vs.size();
    vector<LL> coeff(sz);
    coeff[sz-1] = 1;
    coeff[sz-2] = 1;
    for (int i = sz-3; i >= 0; i--) {
        coeff[i] = coeff[i+1] * 2;
    }
    LL cnt = 0;
    for (int i = sz-1; i > 0; i--) {
        cnt += coeff[i];
    }
    ret.push_back(a);
    b -= coeff[0] * a;
    for (int i = 1; i < sz; i++) {
        cnt -= coeff[i];
        LL y = min(m, (b-cnt)/coeff[i]);
        ret.push_back(y);
        b -= coeff[i] * ret.back();
    }
    cnt = a;
    for (int i = 1; i < sz; i++) {
        ret[i] += cnt;
        cnt += ret[i];
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
    LL a, b, m;
    int q; cin >> q;
    while (q--) {
        cin >> a >> b >> m;
        auto ret = solve(a, b, m);
        assert(ret.size() <= 50);
        if (ret.empty()) {
            cout << -1 << endl;
        } else {
            cout << ret.size() << ' ';
            for (int i = 0; i < ret.size(); i++) {
                cout << ret[i];
                if (i+1 == ret.size()) cout << endl;
                else cout << ' ';
            }
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
