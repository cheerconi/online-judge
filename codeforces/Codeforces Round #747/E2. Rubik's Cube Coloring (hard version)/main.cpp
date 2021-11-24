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
const int mod = 1e9 + 7;
const int MAXN = 66;
LL normal_dp[MAXN];
set<LL> level2nodes[MAXN];
map<string, int> table;
map<LL, vector<LL>> sp_dp;
map<LL, int> sp_count;
int ban[6] = {1, 0, 3, 2, 5, 4};

int level(LL node) {
    int ret = 0;
    while (node > 1) {
        node >>= 1;
        ret++;
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
    table["white"] = 0;
    table["yellow"] = 1;
    table["green"] = 2;
    table["blue"] = 3;
    table["red"] = 4;
    table["orange"] = 5;
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        LL node; cin >> node;
        string s; cin >> s;
        level2nodes[level(node)].insert(node);
        int idx = table[s];
        sp_dp[node] = vector<LL>(6);
        sp_dp[node][idx] = 1;
    }
    normal_dp[n-1] = 1;
    for (int i = n-1; i >= 0; i--) {
        if (i < n-1) {
            for (LL node : level2nodes[i]) {
                auto cur_it = sp_dp.find(node);
                int count = sp_count[node];
                if (count == 0) {
                    for (int j = 0; j < 6; j++) {
                        cur_it->second[j] = cur_it->second[j] * normal_dp[i] % mod;
                    }
                } else if (count == 1) {
                    for (int j = 0; j < 6; j++) {
                        cur_it->second[j] = cur_it->second[j] * 4L % mod * normal_dp[i+1] % mod;
                    }
                } else {
                    assert(count == 2);
                }
            }
        }
        if (i == 0) break;
        normal_dp[i-1] = 16L * normal_dp[i] % mod * normal_dp[i] % mod;
        for (LL node : level2nodes[i]) {
            auto cur_it = sp_dp.find(node);
            LL par = node >> 1;
            auto par_it = sp_dp.find(par);
            if (par_it == sp_dp.end()) {
                par_it = sp_dp.emplace(par, vector<LL>(6, 1)).first;
                level2nodes[i-1].insert(par);
            }
            sp_count[par]++;
            for (int j = 0; j < 6; j++) {
                if (par_it->second[j] == 0) continue;
                LL tmp = 0;
                for (int k = 0; k < 6; k++) {
                    if (j == k || ban[j] == k) continue;
                    tmp = (tmp + cur_it->second[k]) % mod;
                }
                par_it->second[j] = par_it->second[j] * tmp % mod;
            }
        }
    }
    LL ret = 0;
    auto root_it = sp_dp.find(1);
    for (LL value : root_it->second) {
        ret = (ret + value) % mod;
    }
    cout << ret << '\n';







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
