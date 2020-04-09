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
int x[MAXN], y[MAXN], cnt[2][MAXN];

pii solve(int q, const string& s) {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'W') {
            cnt[0][0]++;
            cnt[0][x[i]]--;
        } else if (s[i] == 'E') {
            cnt[0][x[i]+1]++;
        }
        else if (s[i] == 'N') {
            cnt[1][y[i]+1]++;
        } else {
            cnt[1][0]++;
            cnt[1][y[i]]--;
        }
    }
    int idx[2] = {0};
    for (int i = 1; i <= q; i++) {
        for (int k = 0; k < 2; k++) {
            cnt[k][i] += cnt[k][i-1];
            if (cnt[k][i] > cnt[k][idx[k]]) idx[k] = i;
        }
    }
    return {idx[0], idx[1]};
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
        int p, q;
        cin >> p >> q;
        string s(p, 'x');
        for (int i = 0; i < p; i++) {
            cin >> x[i] >> y[i] >> s[i];
        }
        pii ans = solve(q, s);
        cout << "Case #" << cs << ": " << ans.first << ' ' << ans.second << endl;
    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
