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
string dp[2][21][40][40];
int powera[21], powerb[21];
int a, b;
void dfs(const string& s, int end, int i, int num_red, int x, int y, string& cur, int idx) {
    if (i == end) {
        if (dp[idx][num_red][x][y].empty()) dp[idx][num_red][x][y] = cur;
        return;
    }
    int val = s[i] - '0';
    cur.push_back('R');
    dfs(s, end, i+1, num_red+1, (x*10+val)%a, y, cur, idx);
    cur.back() = 'B';
    dfs(s, end, i+1, num_red, x, (y*10+val)%b, cur, idx);
    cur.pop_back();
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int T; cin >> T;
    string s;
    int n;
    while (T--) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 21; j++) {
                for (int k = 0; k < 40; k++) {
                    for (int u = 0; u < 40; u++) {
                        dp[i][j][k][u].clear();
                    }
                }
            }
        }
        cin >> n >> a >> b;
        powera[0] = 1;
        powerb[0] = 1;
        for (int i = 1; i < 21; i++) {
            powera[i] = powera[i-1] * 10 % a;
            powerb[i] = powerb[i-1] * 10 % b;
        }
        cin >> s;
        int mid = n / 2;
        string cur;
        dfs(s, mid, 0, 0, 0, 0, cur, 0);
        dfs(s, n, mid, 0, 0, 0, cur, 1);
        string ret;
        int diff = INT_MAX;
        for (int len_red_0 = 0; len_red_0 <= mid; len_red_0++) {
            int len_black_0 = mid - len_red_0;
            for (int res_red_0 = 0; res_red_0 < a; res_red_0++) {
                for (int res_black_0 = 0; res_black_0 < b; res_black_0++) {
                    if (dp[0][len_red_0][res_red_0][res_black_0].empty()) continue;
                    for (int len_red_1 = 0; len_red_1 <= n-mid; len_red_1++) {
                        int len_black_1 = n-mid - len_red_1;
                        if (abs(len_black_1 + len_black_0 - len_red_1 - len_red_0) >= diff) continue;
                        if (len_black_1 + len_black_0 == 0) continue;
                        if (len_red_1 + len_red_0 == 0) continue;
                        int res_red_1 = (a - res_red_0 * powera[len_red_1] % a) % a;
                        int res_black_1 = (b - res_black_0 * powerb[len_black_1] % b) % b;
                        if (!dp[1][len_red_1][res_red_1][res_black_1].empty()) {
                            diff = abs(len_black_1 + len_black_0 - len_red_1 - len_red_0);
                            ret = dp[0][len_red_0][res_red_0][res_black_0] + dp[1][len_red_1][res_red_1][res_black_1];
                        }
                    }
                }
            }
        }
        if (ret.empty()) ret = "-1";
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
