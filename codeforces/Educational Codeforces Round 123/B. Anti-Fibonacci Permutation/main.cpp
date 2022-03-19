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
vector<vi> solve(int n) {
    vector<vi> ret;
    for (int i = 4; i <= n; i++) {
        vi nums;
        nums.push_back(i);
        nums.push_back(1);
        nums.push_back(2);
        for (int j = 3; j <= n; j++) {
            if (i == j) continue;
            nums.push_back(j);
        }
        reverse(nums.begin(), nums.end());
        ret.push_back(move(nums));
        if (ret.size() == n) break;

        nums.clear();
        nums.push_back(i);
        nums.push_back(2);
        nums.push_back(1);
        for (int j = 3; j <= n; j++) {
            if (i == j) continue;
            nums.push_back(j);
        }
        reverse(nums.begin(), nums.end());
        ret.push_back(move(nums));
        if (ret.size() == n) break;
    }
    if (ret.size() != n) {
        vi nums(n);
        iota(nums.begin(), nums.end(), 1);
        reverse(nums.begin(), nums.end());
        ret.push_back(move(nums));
    }
    if (ret.size() != n) {
        vi nums(n);
        iota(nums.begin(), nums.end(), 1);
        reverse(nums.begin(), nums.end());
        swap(nums[n-1], nums[n-2]);
        ret.push_back(move(nums));
    }
    if (ret.size() != n) {
        vi nums(n);
        iota(nums.begin(), nums.end(), 1);
        reverse(nums.begin(), nums.end());
        nums[n-3] = 1;
        nums[n-2] = 3;
        nums[n-1] = 2;
        ret.push_back(move(nums));
    }
    assert(ret.size() == n);
    return ret;
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
        auto ret = solve(n);
        for (const auto& nums : ret) {
            for (int i = 0; i < n; i++) {
                cout << nums[i];
                if (i+1 == n) cout << '\n';
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
