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
const int MAXN = 2000 + 10;
string mat[MAXN];
int dp[MAXN][MAXN];
int n, m;

void solve() {
    vector<pii> ps;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] != -1) continue;
            ps.clear();
            ps.emplace_back(i, j);
            dp[i][j] = 0;
            pii duplicate{-1, -1};
            int base = 0;
            while (true) {
                auto [x, y] = ps.back();
                if (mat[x][y] == 'L') y--;
                else if (mat[x][y] == 'R') y++;
                else if (mat[x][y] == 'U') x--;
                else x++;
                if (x < 0 || x >= n || y < 0 || y >= m) break;
                if (dp[x][y] == 0) {
                    duplicate = {x, y};
                    break;
                }
                if (dp[x][y] > 0) {
                    base = dp[x][y];
                    break;
                }
                dp[x][y] = 0;
                ps.emplace_back(x, y);
            }
            if (duplicate.first != -1) {
                int pivot = 0;
                for (; pivot < ps.size(); pivot++) {
                    if (ps[pivot] == duplicate) break;
                }
                assert(pivot < ps.size());
                for (int k = pivot; k < ps.size(); k++) {
                    auto [x, y] = ps[k];
                    dp[x][y] = ps.size() - pivot;
                }
                for (int k = 0; k < pivot; k++) {
                    auto [x, y] = ps[k];
                    dp[x][y] = ps.size() - k;
                }
            } else {
                for (int k = 0; k < ps.size(); k++) {
                    auto& [x, y] = ps[k];
                    dp[x][y] = base + (int)ps.size() - k;
                }
            }
        }
    }
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
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> mat[i];
            for (int j = 0; j < m; j++) {
                dp[i][j] = -1;
            }
        }
        solve();
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] > dp[x][y]) {
                    x = i;
                    y = j;
                }
            }
        }
        cout << x+1 << ' ' << y+1 << ' ' << dp[x][y] << '\n';




    }







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
