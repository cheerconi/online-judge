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
LL nums[MAXN];
vector<vi> ops;

bool solve(int n) {
    ops.clear();
    if (nums[n-3] > nums[n-2] || nums[n-2] > nums[n-1]) {
        ops.push_back({n-3, n-2, n-1});
        nums[n-3] = nums[n-2] - nums[n-1];
    }
    if (nums[n-3] > nums[n-2] || nums[n-2] > nums[n-1]) {
        return false;
    }
    for (int i = n-4; i >= 0; i--) {
        if (nums[i] <= nums[i+1]) continue;
        ops.push_back({i, i+1, n-1});
        nums[i] = nums[i+1] - nums[n-1];
        if (nums[i] > nums[i+1]) return false;
    }
    return true;
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        if (solve(n)) {
            cout << ops.size() << '\n';
            for (const auto& op : ops) {
                cout << op[0]+1 << ' ' << op[1]+1 << ' ' << op[2]+1 << '\n';
            }

        } else {
            cout << "-1\n";
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
