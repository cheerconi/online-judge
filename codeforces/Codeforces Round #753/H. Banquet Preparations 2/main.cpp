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
const int MAXN = 2e6 + 10;
vector<vector<int>> data1[MAXN];
int nums[MAXN][3];
int eaten[MAXN][2];

void solve(vector<int>& todo, int mi) {
    while (!todo.empty()) {
        int i = todo.back(); todo.pop_back();
        assert(mi != -1);
        eaten[i][0] = nums[i][0] - mi;
        eaten[i][1] = nums[i][2] - eaten[i][0];
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
        vector<int> used;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            eaten[i][0] = 0;
            eaten[i][1] = 0;
            cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
            int tot = nums[i][0] + nums[i][1] - nums[i][2];
            if (data1[tot].empty()) used.push_back(tot);
            int mi = max(0, nums[i][0] - nums[i][2]);
            int ma = min(tot, nums[i][0]);
            data1[tot].push_back({mi, ma, i});
        }
        int ret = 0;
        for (int idx : used) {
            sort(data1[idx].begin(), data1[idx].end(), [](const vi& a, const vi& b) {
               return a[1] < b[1];
            });
            int mi = -1, ma = -1;
            vector<int> todo;
            for (const vi& item : data1[idx]) {
                if (mi == -1 || ma < item[0] || item[1] < mi) {
                    if (!todo.empty()) ret++;
                    solve(todo, mi);
                    mi = item[0];
                    ma = item[1];
                } else {
                    mi = max(mi, item[0]);
                    ma = min(ma, item[1]);
                }
                todo.push_back(item[2]);
            }
            if (!todo.empty()) ret++;
            solve(todo, mi);
            data1[idx].clear();
        }
        cout << ret << '\n';
        for (int i = 0; i < n; i++) {
            cout << eaten[i][0] << ' ' << eaten[i][1] << '\n';
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
