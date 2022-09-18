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
const int MAXN = 40;
int mat[MAXN][MAXN];
pii pos[MAXN*MAXN];
map<int, int> dp[MAXN*MAXN];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};


void build(int n) {
    memset(mat, -1, sizeof(mat));
    int i = 0, j = 0;
    int val = 1;
    int k = 0;
    while (true) {
        assert(i >= 0 && i < n && j < n && j >= 0 && mat[i][j] == -1);
        mat[i][j] = val;
        pos[val] = {i, j};
        if (val == n * n) break;
        val++;
        int ii = i + dx[k];
        int jj = j + dy[k];
        if (ii == n || ii == -1 || jj == n || jj == -1 || mat[ii][jj] != -1) {
            k = (k+1) % 4;
            ii = i + dx[k];
            jj = j + dy[k];
        }
        i = ii;
        j = jj;
    }
}

std::vector<pii> solve(int n, int k) {
    build(n);
    for (int i = n*n; i >= 1; i--) {
        dp[i].clear();
    }
    dp[n*n][0] = n*n;
    dp[n*n-1][1] = n*n;
    for (int u = n*n-2; u >= 1; u--) {
        auto [i, j] = pos[u];
        for (int v = 0; v < 4; v++) {
            int ii = i + dx[v];
            int jj = j + dy[v];
            if (ii == -1 || ii == n || jj == -1 || jj == n) continue;
            if (mat[ii][jj] < mat[i][j]) continue;
            for (const auto& [step, _] : dp[mat[ii][jj]]) {
                dp[u][step+1] = mat[ii][jj];
            }
        }
    }
    if (dp[1].find(k) == dp[1].end()) {
        return {};
    }
    std::vector<pii> ret;
    int i = 1;
    while (i < n*n) {
        auto iter =  dp[i].find(k);
        assert(iter != dp[i].end());
        if (iter->second - i > 1) {
            ret.emplace_back(i, iter->second);
        }
        k--;
        i = iter->second;
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
    int T; cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        int n, k; cin >> n >> k;
       auto ret = solve(n, k);
       cout << "Case #" << cs << ": ";
       if (ret.empty()) {
           cout << "IMPOSSIBLE\n";
       } else {
           cout << ret.size() << "\n";
           for (const auto [x, y] : ret) {
               cout << x << ' ' << y << endl;
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
