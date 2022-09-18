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
const int MAXN = 1e9;





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
//  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int T; cin >> T;
    vector<LL> nums;
    for (int i = 0; i < 30; i++) {
        nums.push_back(1<<i);
    }
    for (int i = 0; i < 70; i++) {
        nums.push_back(MAXN-i);
    }
    while (T--) {
        int n; cin >> n;
        assert(n == 100);
        LL sum = 0;
        for (int i = 0; i < n; i++) {
            cout << nums[i];
            sum += nums[i];
            if (i+1 == n) cout << endl;
            else cout << ' ';
        }
        vector<LL> bs;
        for (int i = 0; i < 100; i++) {
            int val; cin >> val;
            sum += val;
            bs.push_back(val);
        }
        sum /= 2;
        vector<int> ret;
        for (int num : bs) {
            if (sum - num >= 0) {
                sum -= num;
                ret.push_back(num);
            }
        }
        for (int i = 30; i < n; i++) {
            if (sum - nums[i] >= 0) {
                sum -= nums[i];
                ret.push_back(nums[i]);
            }
        }
        LL mask = (1LL<<30) - 1;
        assert(sum <= mask);
        for (int i = 0; i < 30; i++) {
            if ((1<<i) & sum) {
                ret.push_back(1<<i);
            }
        }
        for (int i = 0; i < ret.size(); i++) {
            cout << ret[i];
            if (i+1 == ret.size()) cout << endl;
            else cout << ' ';
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
