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
const int MAXV = 5e6 + 10;
int factor[MAXV];
LL cnt[MAXV], raw_cnt[MAXV], dp[MAXV];
vi edges[MAXV];
vi nums;

vector<pii> get_factors(int val) {
    vector<pii> items;
    while (factor[val] > 0) {
        if (items.empty() || items.back().first != factor[val]) {
            items.emplace_back(factor[val], 1);
        } else {
            items.back().second++;
        }
        val /= factor[val];
    }
    if (val > 1) {
        if (items.empty() || items.back().first != val) {
            items.emplace_back(val, 1);
        } else {
            items.back().second++;
        }
    }
    return items;
}

void dfs(const vector<pii>& items, int i, int val) {
    if (i == items.size()) {
        nums.push_back(val);
        return;
    }
    for (int j = 0; j <= items[i].second; j++) {
        dfs(items, i+1, val);
        val *= items[i].first;
    }
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n; cin >> n;
    int ma = 0, val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        ma = max(ma, val);
        raw_cnt[val]++;
    }
    for (int i = 2; i <= ma; i++) {
        if (factor[i] != 0) continue;
        for (int j = i+i; j <= ma; j += i) {
            factor[j] = i;
        }
    }

    for (int i = ma; i >= 1; i--) {
        if (cnt[i] == 0 && raw_cnt[i] == 0) continue;
        dp[i] = i * raw_cnt[i];
        vector<pii> items = get_factors(i);
        nums.clear();
        dfs(items, 0, 1);
        for (int num : nums) {
            cnt[num] += raw_cnt[i];
        }
        edges[i] = move(nums);
    }
    LL ret = 0;
    for (int w = ma; w >= 1; w--) {
        ret = max(ret, dp[w]);
        for (int u : edges[w]) {
            if (u == w) continue;
            dp[u] = max(dp[u], dp[w] + (cnt[u] - cnt[w]) * u);
        }
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
