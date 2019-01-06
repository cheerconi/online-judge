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
constexpr int MAXN = 100000 + 10;
constexpr int mod = 1e9 + 7;
vector<int> ps;
int mu[MAXN], factor[MAXN], power[MAXN];
map<int, int> table;
map<int, map<int, int>> cache;
set<int> vals;

void dfs(set<int>::iterator it, int val, int cur) {
    if (it == vals.end()) {
        cache[val][cur]++;
        return;
    }
    int tmp = *it;
    it++;
    dfs(it, val, cur);
    dfs(it, val, cur*tmp);
}

void solve(int val) {
    auto it = cache.find(val);
    if (it == cache.end()) {
        dfs(vals.begin(), val, 1);
        it = cache.find(val);
    }
    for (auto &items : it->second) {
        table[items.first] += items.second;
    }



}

void init() {
    mu[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (factor[i] == 0) {
            mu[i] = -1;
            ps.push_back(i);
        }
        for (int p : ps) {
            if ((LL)p*i >= MAXN) break;
            if (i % p == 0) break;
            mu[i*p] = -mu[i];
        }
        if (factor[i]) continue;
        for (LL j = (LL)i*i; j < MAXN; j += i) {
            factor[j] = i;
        }
    }
    power[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        power[i] = power[i-1] * 2LL % mod;
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
    int n, num, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        vals.clear();
        while (factor[num] != 0) {
            vals.insert(factor[num]);
            num /= factor[num];
        }
        if (num != 1) vals.insert(num);
        val = 1;
        for (int tmp : vals) val *= tmp;
        solve(val);
    }
    LL ret = 0;
    for (auto& items : table) {
        LL tmp = (power[items.second] - 1 + mod) % mod;
        ret = (ret + mu[items.first] * tmp % mod + mod) % mod;
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
