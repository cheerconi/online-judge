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
const int MAXN = 12;
int px[MAXN], py[MAXN];
int sx[MAXN], sy[MAXN];
bool used[MAXN];
vector<int> cur;
vector<pii> p2s[MAXN];
vector<pii> final;

void solve(const vector<int>& item) {
    vector<pii> ret;
    int n = item.size();
    vector<int> tmp(n+1);
    auto p2ss = p2s;
    while (true) {
        bool done = true;
        for (int i = 0; i < n; i++) {
            while (tmp[p2s[i].back().second]) {
                p2s[i].pop_back();
            }
            if (p2s[i].empty()) break;
            int min_dist = p2s[i].back().first;
            for (int j = p2s[i].size()-1; j >= 0; j--) {
                auto& [dist, sweet] = p2s[i][j];
                if (dist != min_dist) break;
                if (tmp[sweet]) continue;
                if (sweet == item[i]) {
                    ret.emplace_back(i, sweet);
                    tmp[sweet] = true;
                    done = false;
                    break;
                }
            }
        }
        if (done) break;
    }
    if (ret.size() == n) final = ret;
}



void dfs(int n) {
    if (cur.size() == n) {
        solve(cur);
        return;

    }
    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        cur.push_back(i);
        used[i] = true;
        dfs(n);
        used[i] = false;
        cur.pop_back();
        if (!final.empty()) return;
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
    for (int cs = 1; cs <= T; cs++) {
        final.clear();
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            p2s[i].clear();
        }
        for (int i = 0; i < n; i++) {
            cin >> px[i] >> py[i];
        }
        for (int i = 0; i <= n; i++) {
            cin >> sx[i] >> sy[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                int dist = abs(px[i] - sx[j]) + abs(py[i] - sy[j]);
                p2s[i].emplace_back(dist, j);
            }
            sort(p2s[i].begin(), p2s[i].end(), greater<pii>());
        }
        dfs(n);
        cout << "Case #" << cs << ": ";
        if (final.empty()) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << "POSSIBLE\n";
            for (const auto[x, y] : final) {
                cout << x +1 << ' ' << y +1<< '\n';
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
