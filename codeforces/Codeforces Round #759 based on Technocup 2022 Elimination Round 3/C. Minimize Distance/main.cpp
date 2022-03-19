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
int nums[MAXN];

LL solve(int n, int k) {
    vector<LL> ret;
    int i = n-1;
    while (i >= 0 && nums[i] > 0) {
        ret.push_back(nums[i]);
        for (int j = 0; j < k; j++) {
            i--;
            if (i < 0 || nums[i] <= 0) break;
        }
    }
    i = 0;
    while (i < n && nums[i] < 0) {
        ret.push_back(-nums[i]);
        for (int j = 0; j < k; j++) {
            i++;
            while (i >= n || nums[i] >= 0) break;
        }
    }
    sort(ret.begin(), ret.end());
    LL sum = 0;
    for (LL num : ret) {
        sum += num * 2;
    }
    if (!ret.empty()) sum -= ret.back();
    return sum;

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
        int n, k; cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        sort(nums, nums+n);
        cout << solve(n, k) << '\n';

    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
