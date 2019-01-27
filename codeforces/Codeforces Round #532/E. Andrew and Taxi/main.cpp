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
const int MAXN = 100000 + 10;
vector<int> edges[MAXN];
int degree[MAXN], a[MAXN], b[MAXN], c[MAXN], n;
map<int, int> ret;

void toposort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) q.push(i);
    }
    ret.clear();
    int tot = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop(); ret[cur] = tot++;
        for (int nxt : edges[cur]) {
            degree[nxt]--;
            if (degree[nxt] == 0) q.push(nxt);
        }
    }
}
bool solve(int m, int k) {
    for (int i = 1; i <= n; i++) edges[i].clear();
    memset(degree, 0, sizeof(degree));
    for (int i = 0; i < m; i++) {
        if (c[i] > k) {
            edges[a[i]].push_back(b[i]);
            degree[b[i]]++;
        }
    }
    toposort();
    return ret.size()==n;
}





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    int x = 0, y = 1e9;
    while (x < y) {
        int mid = (x + y) >> 1;
        if (solve(m, mid)) y = mid;
        else x = mid + 1;
    }
    solve(m, x);
    vector<int> vs;
    for (int i = 0; i < m; i++) {
        if (c[i] > x) continue;
        if (ret[a[i]] > ret[b[i]]) vs.push_back(i+1);
    }
    cout << x << ' ' << vs.size() << endl;
    for (int i = 0; i < vs.size(); i++) {
        cout << vs[i];
        if (i+1 == vs.size()) cout << endl;
        else cout << ' ';
    }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
