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
const int MAXB = 30;
vector<int> edges[MAXN];
vector<int> nums[MAXB];
int sz[2];
int label[MAXN];

void dfs(int i, int par, int depth) {
    sz[depth%2]++;
    for (int nxt : edges[i]) {
        if (nxt == par) continue;
        dfs(nxt, i, depth+1);
    }
}

void solve(vector<vector<int>>& used, int i, int par, int depth, int idx) {
    if (depth % 2 == idx) {
        label[i] = used.back().back();
        used.back().pop_back();
        if (used.back().empty()) used.pop_back();
    }
    for (int nxt : edges[i]) {
        if (nxt == par) continue;
        solve(used, nxt, i, depth+1, idx);
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
        sz[0] = 0;
        sz[1] = 0;
        for (int i = 0; i < MAXB; i++) nums[i].clear();
        int n; cin >> n;
        int b = 0;
        for (int i = 1; i <= n; i++) {
            edges[i].clear();
            label[i] = 0;
            while ((1<<(b+1)) & i) {
                b++;
            }
            nums[b].push_back(i);
        }
        for (int i = 0; i < n-1; i++) {
            int a, b; cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        dfs(1, -1, 0);
        vector<vector<int>> used;
        vector<vector<int>> unused;
        int val = min(sz[0], sz[1]);
        while (b >= 0) {
            int mask = 1<<b;
            if (mask & val) {
                bool flag = false;
                for (int i = 0; i < MAXB; i++) {
                    if (nums[i].size() == mask) {
                        used.push_back(move(nums[i]));
                        flag = true;
                        break;
                    }
                }
                assert(flag);
            }
            b--;
        }
        for (int i = 0; i < MAXB; i++) {
            if (!nums[i].empty()) unused.push_back(move(nums[i]));
        }
        if (val == sz[0]) {
            solve(used, 1, -1, 0, 0);
            solve(unused, 1, -1, 0, 1);
        } else {
            solve(used, 1, -1, 0, 1);
            solve(unused, 1, -1, 0, 0);
        }
        assert(used.empty());
        assert(unused.empty());
        for (int i = 1; i <= n; i++) {
            cout << label[i];
            if (i == n) cout << '\n';
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
