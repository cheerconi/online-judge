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
const int MAXN = 5e5 + 10;
struct Query{
    int i, h;
    Query(int _i, int _h) {
        h = _h;
        i = _i;
    }
};
vector<int> edges[MAXN];
vector<int> *pool[MAXN];
string s;
bool ret[MAXN];
int state[MAXN], sz[MAXN], deep[MAXN];
vector<Query> qs[MAXN];

void dfs(int cur, int d) {
    sz[cur] = 1;
    deep[cur] = d;
    for (int nxt : edges[cur]) {
        dfs(nxt, d+1);
        sz[cur] += sz[nxt];
    }
}

void solve(int cur, bool keep) {
    int bigson = -1;
    for (int nxt : edges[cur]) {
        if (bigson == -1) bigson = nxt;
        else if (sz[bigson] < sz[nxt]) {
            bigson = nxt;
        }
    }
    for (int nxt : edges[cur]) {
        if (nxt != bigson) solve(nxt, false);
    }
    if (bigson == -1) {
        pool[cur] = new vector<int>();
    } else {
        solve(bigson, true);
        pool[cur] = pool[bigson];
    }
    pool[cur]->push_back(cur);
    state[deep[cur]] ^= 1<<(s[cur] - 'a');
    for (int nxt : edges[cur]) {
        if (nxt == bigson) continue;
        for (int num : *pool[nxt]) {
            state[deep[num]] ^= 1<< (s[num] - 'a');
            pool[cur]->push_back(num);
        }
    }
    for (auto q : qs[cur]) {
        if (__builtin_popcount(state[q.h]) <= 1) {
            ret[q.i] = true;
        } else {
            ret[q.i] = false;
        }
    }
    if (!keep) {
        for (int num : *pool[cur]) {
            state[deep[num]] ^= 1<< (s[num] - 'a');
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
    int n, m, p, v, h;
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        cin >> p;
        edges[p].push_back(i);
    }
    cin >> s;
    s = "+" + s;

    for (int i = 0; i < m; i++) {
        cin >> v >> h;
        qs[v].emplace_back(i, h);
    }
    dfs(1,1);
    solve(1, true);
    for (int i = 0; i < m; i++) {
        if (ret[i]) cout << "Yes\n";
        else cout << "No\n";
    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
