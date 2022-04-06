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
const int MAXN = 1e5 + 10;
int degree[MAXN];




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
//  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int T; cin >> T;
    while (T--) {
        double ret = 0;
        int n, k; cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            degree[i] = -1;
        }
        int a, b, c, d; cin >> a >> b;
        for (int i = 0; i < k; i += 2) {
            a = mt() % n + 1;
            cout << "T " << a << endl;
            cin >> a >> b;
            degree[a] = b;
            cout << "W" << endl;
            cin >> c >> d;
            degree[c] = d;
            ret += b;
        }
        ret = 2.0 * ret / k;
        LL ret2 = 0;
        int m = 0;
        for (int i = 1; i <= n; i++) {
            if (degree[i] == -1) m++;
            else ret2 += degree[i];
        }
        ret = (ret * m + ret2) / 2;
        cout <<  "E " << (LL)ret << endl;


    }







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
