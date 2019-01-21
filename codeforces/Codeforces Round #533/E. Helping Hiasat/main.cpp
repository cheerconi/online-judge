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
const int MAXN = 50;
bool mat[MAXN][MAXN];
map<string, int> table;
int m, ret, mask, dp[1<<20];

int popcount(int cur) {
    int cnt = 0;
    while (cur) {
        if (cur&1) cnt++;
        cur >>= 1;
    }
    return cnt;
}
bool cmp(int a, int b) {
    return popcount(a) < popcount(b);
}

void build(LL cur) {
    for (int i = 0; i < m; i++) {
        if ((cur&(1LL<<i)) == 0) continue;
        for (int j = i+1; j < m; j++) {
            if ((cur&(1LL<<j)) == 0) continue;
            mat[i][j] = true;
            mat[j][i] = true;
        }
    }
}

void dfs(LL cur, int i) {
    if (i == m) {
        int state = mask, cnt = 0;
        for (int j = m/2; j < m; j++) {
            if (((1LL<<j) & cur) == 0) continue;
            cnt++;
            for (int k = 0; k < m/2; k++) {
                if (mat[k][j] && (state & (1<<k))) state ^= 1<<k;
            }
        }
        ret = max(ret, cnt+dp[state]);
        return;
    }
    dfs(cur, i+1);
    for (int j = 0; j < m; j++) {
        if (mat[i][j] && ((1LL<<j)&cur)) return;
    }
    dfs(cur | (1LL<<i), i+1);
}



int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int q, cmd;
    string s;
    cin >> q >> m;
    LL cur = 0;
    while (q--) {
        cin >> cmd;
        if (cmd == 1) {
            build(cur);
            cur = 0;
        } else {
            cin >> s;
            if (table.find(s) == table.end()) {
                int sz = table.size();
                table[s] = sz;
            }
            cur |= 1LL<<table[s];
        }
    }
    build(cur);
    vector<int> states;
    states.reserve(1<<(m/2));
    for (int i = 0; i < 1<<(m/2); i++) {
        states.push_back(i);
    }
    sort(states.begin(), states.end(), cmp);
    for (int i = 1; i < (1<<(m/2)); i++) {
        int cnt = popcount(states[i]);
        if (cnt <= 1) {
            dp[states[i]] = cnt;
            continue;
        }
        int x = -1, y = -1;
        for (int a = 0; (1<<a) <= states[i] && x == -1; a++) {
            if (((1<<a)&states[i]) == 0) continue;
            for (int b = a+1; (1<<b) <= states[i] && x == -1; b++) {
                if (((1<<b)&states[i]) == 0) continue;
                if (mat[a][b] == true) {
                    x = a;
                    y = b;
                }
            }
        }
        if (x == -1) dp[states[i]] = cnt;
        else dp[states[i]] = max(dp[states[i]^(1<<x)], dp[states[i]^(1<<y)]);
    }
    mask = (1<<(m/2)) - 1;
    dfs(0, m/2);
    cout << ret << endl;








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
