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
const int MAXN = 123;
string data[MAXN];
unordered_set<string> bans;
string one;
int one_v, cur_v;
vector<pii> idxs;

void solve(int i, int p) {
    if (p == i) {
        if (bans.find(one) == bans.end()) {
            one_v = min(one_v, cur_v);
        }
        return;
    }
    solve(i+1, p);
    int idx = idxs[i].second;
    if (one[idx] == '1') one[idx] = '0';
    else one[idx] = '1';
    cur_v += idxs[i].first;
    solve(i+1, p);
    if (one[idx] == '1') one[idx] = '0';
    else one[idx] = '1';
    cur_v -= idxs[i].first;
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
        one.clear(); idxs.clear(); one_v = INT_MAX; cur_v = 0; bans.clear();
        int n, m, p; cin >> n >> m >> p;
        for (int i = 0; i < n; i++) {
            cin >> data[i];
        }
        string s;
        for (int i = 0; i < m; i++) {
            cin >> s;
            bans.insert(s);
        }
        for (int i = 0; i < p; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (data[j][i] == '1') cnt++;
            }
            int tmp = n - cnt;
            if (cnt >= tmp) one.push_back('1');
            else one.push_back('0');
            idxs.emplace_back(abs(cnt-tmp), i);
            cur_v += min(cnt, tmp);
        }
        sort(idxs.begin(), idxs.end());

        solve(0, min(p, 15));
        cout << "Case #" << cs << ": " << one_v << endl;
    }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
