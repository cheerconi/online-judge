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
const int MAXN = 300000 + 10;
LL x[MAXN], y[MAXN], ret[MAXN], vs[MAXN];
pll dist[MAXN];





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        x[i] *= 2;
        y[i] *= 2;
        dist[i] = {x[i] - y[i], i};
    }
    sort(dist, dist+n);
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(dist, dist+n, make_pair(x[i]-y[i], LLONG_MIN)) - dist;
        ret[0] += y[i];
        ret[idx] -= y[i];
        vs[i] += y[i]*idx;
        int idx2 = upper_bound(dist, dist+n, make_pair(x[i]-y[i], LLONG_MAX)) - dist;
        ret[idx] += (x[i] + y[i]) / 2;
        ret[idx2] -= (x[i] + y[i]) / 2;
        vs[i] += (x[i]+y[i]) / 2 * (idx2-idx);
        ret[idx2] += x[i];
        vs[i] += x[i] * (n - idx2);
    }
    for (int i = 1; i < n; i++) {
        ret[i] += ret[i-1];
    }
    for (int i = 0; i < n; i++) {
        vs[dist[i].second] += ret[i];
        vs[dist[i].second] -= x[dist[i].second]+y[dist[i].second];
    }
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        LL tmp = min(x[a]+y[b], x[b]+y[a]);
        vs[a] -= tmp;
        vs[b] -= tmp;
    }
    for (int i = 0; i < n; i++) {
        cout << vs[i]/2;
        if (i+1 == n) cout << endl;
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
