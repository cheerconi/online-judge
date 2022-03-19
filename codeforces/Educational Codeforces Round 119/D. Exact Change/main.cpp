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
const int MAXN = 123;
int nums[MAXN], n;
LL ret;

LL compute(int a, int b, LL val) {
    LL res = INT_MAX;
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            LL tmp = val - i - j*2;
            if (tmp < 0 || tmp % 3 != 0) continue;
            res = min(res, a+b+tmp/3);
        }
    }
    return res;

}

void solve(int a, int b) {
    LL res = a+b;
    for (int i = 0; i < n; i++) {
        res = max(res, compute(a, b, nums[i]));
        if (res > ret) return;
    }
    ret = min(ret, res);
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int a = 5, b = 5;
    int T; cin >> T;
    while (T--) {
        cin >> n;
        ret = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            ret = max(ret, (LL)nums[i]);
        }
        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                solve(i,j);
            }
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
