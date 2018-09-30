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
typedef pair<pii, int> piii;
const int MAXN = 123;
int a[MAXN], b[MAXN];
int suma[3], tot, cur[3];
LL ret_tot, target;


set<piii> table;

void split(int i, int n, int cnt0, int cnt1) {
    if (i == n) {
        if (cnt0 == cnt1 && 3*cnt0 == n) {
            vector<int> ret{cur[0], cur[1], tot-cur[0]-cur[1]};
            sort(ret.begin(), ret.end());
            pii tmp = {ret[0], ret[1]};
            table.insert({tmp, ret[2]});
        }
        return;
    }
    if (3*cnt0 > n || 3*cnt1 > n) return;
    cur[0] += a[i];
    split(i+1, n, cnt0+1, cnt1);
    cur[0] -= a[i];
    cur[1] += a[i];
    split(i+1, n, cnt0, cnt1+1);
    cur[1] -= a[i];
    split(i+1, n, cnt0, cnt1);
}

int cmp() {
    vector<int> p{0, 1, 2};
    int cnt = 0;
    do {
        int vote = 0;
        for (int idx : p) {
            if (suma[idx] > cur[idx]) vote++;
        }
        if (vote >= 2) cnt++;
    } while (next_permutation(p.begin(), p.end()));
    return cnt;
}
void solve(int i, int n, int cnt0, int cnt1) {
    if (i == n) {
        if (cnt0 == cnt1 && 3*cnt0 == n) {
            cur[2] = tot - cur[0] - cur[1];
            ret_tot += 6;
            target += cmp();
        }
        return;
    }
    if (3*cnt0 > n || 3*cnt1 > n) return;
    cur[0] += b[i];
    solve(i+1, n, cnt0+1, cnt1);
    cur[0] -= b[i];
    cur[1] += b[i];
    solve(i+1, n, cnt0, cnt1+1);
    cur[1] -= b[i];
    solve(i+1, n, cnt0, cnt1);
}



int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int T; cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        table.clear();
        int n; cin >> n;
        tot = 0; suma[2] = 0;
        for (int i = 0; i < 3*n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < 3*n; i++) {
            cin >> b[i];
        }
        cur[0] = cur[1] = 0;
        tot = 0;
        for (int i = 0; i < 3*n; i++) tot += a[i];
        split(0, 3*n, 0, 0);
        LD ret_real = 0;
        tot = 0;
        for (int i = 0; i < 3*n; i++) tot += b[i];
        for (auto &item : table) {
            ret_tot = 0; target = 0;

            suma[0] = item.first.first;
            suma[1] = item.first.second;
            suma[2] = item.second;

            solve(0, 3*n, 0, 0);
            ret_real = max(ret_real, (LD)target/ret_tot);
        }

        cout << "Case #" << cs << ": " << ret_real << endl;

    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
