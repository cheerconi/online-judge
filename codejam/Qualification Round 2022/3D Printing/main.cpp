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
int nums[10][10];




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int T; cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> nums[i][j];
            }
        }
        for (int j = 0; j < 4; j++) {
            for (int i = 1; i < 3; i++) {
                nums[i][j] = min(nums[i][j], nums[i-1][j]);
            }
        }
        int tot = 1e6;
        for (int j = 0; j < 4; j++) {
            nums[2][j] = min(tot, nums[2][j]);
            tot -= nums[2][j];
        }
        cout << "Case #" << cs << ": ";
        if (tot != 0) {
            cout << "IMPOSSIBLE\n";
        } else {
            for (int j = 0; j < 4; j++) {
                cout << nums[2][j];
                if (j+1 == 4) cout << '\n';
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
