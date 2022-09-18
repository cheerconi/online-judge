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
struct Trie {
    int mask = 0;
    int pre = -1;
    vector<int> nxt;
};
vector<Trie> tries;

const int MAXN = 123;
int mat[MAXN][MAXN], sum[MAXN];
int n, m;

map<int, int> update(const map<int, int>& dp, int a, int b, int nums[]) {
    vector<map<int, int>> tmp_dp(max(a, b)+1);
    for (const auto& [idx, value] : dp) {
        int tmp_len = a;
        int tmp_idx = idx;
        while (tmp_len >= 0) {
            auto it = tmp_dp[tmp_len].find(tmp_idx);
            if (it == tmp_dp[tmp_len].end() || it->second > value + a - tmp_len) {
                tmp_dp[tmp_len][tmp_idx] = value + a - tmp_len;
            }
            tmp_len--;
            tmp_idx = tries[tmp_idx].pre;
        }
        assert(tmp_idx == -1);
    }
    for (int i = 0; i < b; i++) {
        for (const auto& [idx, value] : tmp_dp[i]) {
            int mask = tries[idx].mask;
            vector<int> cur;
            bool flag = true;
            for (int j = 0; j < m; j++) {
                cur.push_back(mask % 4);
                mask /= 4;
                if (cur[j] > nums[j]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) continue;
            for (int j = 0; j < m; j++) {
                if (cur[j] == nums[j]) continue;
                if (tries[idx].nxt.empty()) tries[idx].nxt = vector<int>(m, -1);
                if (tries[idx].nxt[j] == -1) {
                    int tot = tries.size();
                    tries.emplace_back();
                    tries[idx].nxt[j] = tot;
                    tries[tot].pre = idx;
                    tries[tot].mask = tries[idx].mask + (1<<(2*j));
                }
                int nxt = tries[idx].nxt[j];
                auto it = tmp_dp[i+1].find(nxt);
                if (it == tmp_dp[i+1].end() || it->second > value + 1) {
                    tmp_dp[i+1][nxt] = value+1;
                }
            }
        }
    }
    for (auto it = tmp_dp[b].begin(); it != tmp_dp[b].end(); ) {
        int mask = tries[it->first].mask;
        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (mask%4 > nums[j]) {
                flag = false;
                break;
            }
            mask /= 4;
        }
        if (flag) {
            it++;
        } else {
            it = tmp_dp[b].erase(it);
        }
    }
    return tmp_dp[b];
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
        tries.clear();
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            sum[i] = 0;
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
                sum[i] += mat[i][j];
            }
        }
        sum[n] = 0;
        for (int j = 0; j < m; j++) {
            mat[n][j] = 0;
        }
        tries.emplace_back();
        map<int, int> dp;
        dp.emplace(0, 0);
        dp = update(dp, 0, sum[0], mat[0]);
        for (int i = 1; i <= n; i++) {
            dp = update(dp, sum[i-1], sum[i], mat[i]);
        }
        cout << "Case #" << cs << ": "  << dp[0] << '\n';
    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
