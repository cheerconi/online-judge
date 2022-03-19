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
const int MAXV = 1e6 + 10;
vector<pii> nums[MAXN];
int fact[MAXV];

LL solve(vector<pii>&& items) {
    int n = items.size();
    LL ret = 0;
    for (int i = 0; i < n; i++) {
        if (items[i].first == 1) continue;
        LL a = 0, b = 0;
        if (i-1 >= 0 && items[i-1].first == 1) {
            a = items[i-1].second;
        }
        if (i+1 < n && items[i+1].first == 1) {
            b = items[i+1].second;
        }
        ret += (a+1) * (b+1) - 1;
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
    for (int i = 2; i < MAXV; i++) {
        if (fact[i] != 0) continue;
        for (int j = i+i; j < MAXV; j += i) {
            fact[j] = i;
        }
    }
    int T; cin >> T;
    while (T--) {
        LL ret = 0;
        int n, e; cin >> n >> e;
        for (int i = 0; i < n; i++) {
            int val; cin >> val;
            if (val > 2 && fact[val] != 0) {
                ret += solve(move(nums[i%e]));
                nums[i%e].clear();
                continue;
            }
            if (val == 1) {
                if (!nums[i%e].empty() && nums[i%e].back().first == 1) {
                    nums[i%e].back().second++;
                } else {
                    nums[i%e].emplace_back(val, 1);
                }

            } else {
                nums[i%e].emplace_back(val, 1);
            }
        }
        for (int i = 0; i < e; i++) {
            ret += solve(move(nums[i]));
            nums[i].clear();
        }
        cout << ret << '\n';
    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
