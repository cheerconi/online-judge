#include <iostream>
#include <climits>
#include <memory.h>
#include <random>
#include <ctime>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
#ifdef LOCAL
    #define DEBUG(x) { cerr << "# " << #x << ": " << x << endl;}
#else
    #define DEBUG(x)
#endif
mt19937_64 mt(time(0));
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/
const int MAXN = 1e5 + 10;
queue<int> qs[110];
vector<int> edges[MAXN];
int dist[MAXN][110];

void solve(int key) {
    while (!qs[key].empty()) {
        int cur = qs[key].front(); qs[key].pop();
        for (int nxt : edges[cur]) {
            if (dist[nxt][key] != -1) continue;
            dist[nxt][key] = dist[cur][key] + 1;
            qs[key].push(nxt);
        }
    }
}


/*-------------------------------------coding area end------------------------------------------*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
    #ifdef LOCAL
        freopen("../test.txt", "r", stdin);
//        freopen("../output.txt", "w", stdout);
    #endif
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/
    int n, m, k, s, a, b;
    cin >> n >> m >> k >> s;
    memset(dist, -1, sizeof(dist));
    for (int i = 1; i <= n; i++) {
        cin >> a;
        qs[a].push(i);
        dist[i][a] = 0;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 1; i <= k; i++) {
        solve(i);
    }
    for (int i = 1; i <= n; i++) {
        sort(dist[i]+1, dist[i]+k+1);
        int cnt = 0;
        for (int j = 1; j <= s; j++) {
            cnt += dist[i][j];
        }
        cout << cnt;
        if (i == n) cout << endl;
        else cout << ' ';
    }





/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
