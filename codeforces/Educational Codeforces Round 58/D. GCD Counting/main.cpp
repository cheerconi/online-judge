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
const int MAXN = 2e5 + 10;
int factor[MAXN], nums[MAXN], ret;
vector<int> edges[MAXN];
map<int, int> dp[MAXN];
void init() {
    for (LL i = 2;  i < MAXN; i++) {
        if (factor[i] != 0) continue;
        for (LL j = i*i; j < MAXN; j += i) {
            factor[j] = i;
        }
    }
}

void dfs(int root, int par) {
    for (int nxt : edges[root]) {
        if (nxt == par) continue;
        dfs(nxt, root);
    }
    for (auto& item : dp[root]) {
        ret = max(ret, 1);
        for (int nxt : edges[root]) {
            if (nxt == par) continue;
            auto it = dp[nxt].find(item.first);
            if (it == dp[nxt].end()) continue;
            ret = max(ret, item.second + it->second);
            item.second = max(item.second, 1 + it->second);
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
    int n, val, a, b;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val;
        nums[i] = val;
        while (factor[val] != 0) {
            int tmp = factor[val];
            while (val % tmp == 0) val /= tmp;
            dp[i][tmp] = 1;
        }
        if (val != 1) dp[i][val] = 1;
    }
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1, 0);
    cout << ret << endl;





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
