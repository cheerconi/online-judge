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
LL find_k(LL n) {
    n = n * 2;
    LL k = 1;
    while (k * (k-1) < n) {
        k++;
    }
    if (k * (k-1) == n) return k;
    return -1;
}
vector<int> ret[MAXN];




int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    LL n; cin >> n;
    LL k = find_k(n);
    if (k == -1) {
        cout << "No" << endl;
        return 0;
    }
    vector<pii> ps;
    for (int i = 0; i < k; i++) {
        for (int j = i+1; j < k; j++) {
            ps.emplace_back(i, j);
        }
    }
    for (int i = 0; i < ps.size(); i++) {
        ret[ps[i].first].push_back(i+1);
        ret[ps[i].second].push_back(i+1);
    }
    cout << "Yes" << endl << k << endl;
    for (int i = 0; i < k; i++) {
        auto item = ret[i];
        cout << item.size();
        for (int num : item) {
            cout << " " << num;
        }
        cout << endl;
    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
