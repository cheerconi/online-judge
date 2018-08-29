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
const int MAXN = 1e5 + 10;
int color[MAXN], sz[MAXN];
LL cnt[MAXN], ret[MAXN], table[MAXN];
vector<int> edges[MAXN];
vector<int>* pool[MAXN];
int mx;
void count_sz(int cur, int p) {
    sz[cur] = 1;
    for (int nxt : edges[cur]) {
        if (nxt == p) continue;
        count_sz(nxt, cur);
        sz[cur] += sz[nxt];
    }
}

void solve(int cur, int p, bool keep) {
    int son = -1;
    for (int nxt : edges[cur]) {
        if (nxt == p) continue;
        if (son == -1) son = nxt;
        else if (sz[son] < sz[nxt]) {
            son = nxt;
        }
    }
    for (int nxt : edges[cur]) {
        if (nxt == son || nxt == p) continue;
        solve(nxt, cur, false);
    }
    if (son == -1) pool[cur] = new vector<int>();
    else {
        solve(son, cur, true);
        pool[cur] = pool[son];
    }
    cnt[color[cur]]++;
    table[cnt[color[cur]]-1] -= color[cur];
    table[cnt[color[cur]]] += color[cur];
    if (mx == cnt[color[cur]]-1) mx++;
    pool[cur]->push_back(cur);
    for (int nxt : edges[cur]) {
        if (nxt == son || nxt == p) continue;
        for (int tmp : *pool[nxt]) {
            cnt[color[tmp]]++;
            table[cnt[color[tmp]]-1] -= color[tmp];
            table[cnt[color[tmp]]] += color[tmp];
            if (mx == cnt[color[tmp]]-1) mx++;
            pool[cur]->push_back(tmp);
        }
    }
    ret[cur] = table[mx];
    if (!keep) {
        for (int i = 0; i < sz[cur]; i++) {
            LL tmp = (*pool[cur])[i];
            cnt[color[tmp]]--;
            table[cnt[color[tmp]]+1] -= color[tmp];
            table[cnt[color[tmp]]] += color[tmp];
            if (mx == cnt[color[tmp]]+1 && table[mx] == 0) mx--;
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

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }
    LL a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    count_sz(1, 0);
    solve(1, 0, true);
    for (int i = 1; i <= n; i++) {
        cout << ret[i];
        if (i == n) cout << endl;
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
