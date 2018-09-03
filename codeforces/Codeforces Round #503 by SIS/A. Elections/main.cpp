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
const int MAXN = 3000 + 10;
vector<LL> prices[MAXN];
LL ret;
int n, m;

void solve(int k) {
    LL cnt_price = 0;
    int cnt = prices[1].size();
    vector<LL> cands;
    for (int i = 2; i <= m; i++) {
        int a = 0;
        for (; a < (int)prices[i].size()-k+1; a++) {
            cnt_price += prices[i][a];
            cnt++;
        }
        if (cnt  > k || cnt_price >= ret) return;
        for (; a < prices[i].size(); a++) {
            cands.push_back(prices[i][a]);
        }
    }
    sort(cands.begin(), cands.end());
    for (int i = 0; i < k - cnt; i++) {
        cnt_price += cands[i];
    }
    ret = min(ret, cnt_price);
}






int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        prices[a].push_back(b);
    }
    for (int i = 2; i <= m; i++) {
        sort(prices[i].begin(), prices[i].end());
    }
    ret = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        solve(i);
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
