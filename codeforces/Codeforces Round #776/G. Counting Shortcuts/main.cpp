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
const int mod = 1e9 + 7;
vector<int> edges[MAXN];
int dist[MAXN], idx[MAXN];
LL dp[MAXN][2];


int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            edges[i].clear();
            dist[i] = -1;
            idx[i] = i;
            dp[i][0] = -1;
            dp[i][1] = -1;
        }
        int s, t; cin >> s >> t;
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        queue<int> q;
        q.push(s);
        dist[s] = 0;
        int d = 0;
        while (!q.empty()) {
            int sz = q.size();
            d++;
            while (sz--) {
                int i = q.front(); q.pop();
                for (int j : edges[i]) {
                    if (dist[j] == -1) {
                        q.push(j);
                        dist[j] = d;
                    }
                }
            }
        }
        sort(idx+1, idx+1+n, [](int i, int j){
            return dist[i] < dist[j];
        });
        dp[s][0] = 1;
        for (int k = 1; k <= n; k++) {
            int i = idx[k];
            if (dp[i][0] == -1) continue;
            for (int j : edges[i]) {
                if (dist[i] + 1 != dist[j]) continue;
                if (dp[j][0] == -1) dp[j][0] = 0;
                dp[j][0] = (dp[j][0] + dp[i][0]) % mod;
            }
        }
        for (int k = 1; k <= n; k++) {
            int i = idx[k];
            if (dp[i][0] == -1) continue;
            for (int j : edges[i]) {
                if (dist[i] != dist[j]) continue;
                if (dp[j][1] == -1) dp[j][1] = 0;
                dp[j][1] = (dp[j][1] + dp[i][0]) % mod;

            }
        }
        for (int k = 1; k <= n; k++) {
            int i = idx[k];
            if (dp[i][1] == -1) continue;
            for (int j : edges[i]) {
                if (dist[i] + 1 != dist[j]) continue;
                if (dp[j][1] == -1) dp[j][1] = 0;
                dp[j][1] = (dp[j][1] + dp[i][1]) % mod;

            }
        }
        if (dp[t][1] == -1) dp[t][1] = 0;
        if (dp[t][0] == -1) dp[t][0] = 0;
        cout << (dp[t][1] + dp[t][0]) % mod << '\n';
    }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
