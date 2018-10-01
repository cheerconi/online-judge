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
string s;
vector<int> edges[MAXN];
int degree[MAXN][2];
bool del[MAXN];





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n, m, a, b;
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
        degree[a][s[b]-'A']++;
        degree[b][s[a]-'A']++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (degree[i][0] == 0 || degree[i][1] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (del[cur]) continue;
        del[cur] = true;
        for (int nxt : edges[cur]) {
            if (del[nxt] && nxt != cur) continue;
            degree[nxt][s[cur]-'A']--;
            if (degree[nxt][s[cur]-'A'] == 0) {
                q.push(nxt);
            }
        }
    }
    bool ret = false;
    for (int i = 0; i < n; i++) {
        if (!del[i]) ret = true;
    }
    if (ret) cout << "Yes" << endl;
    else cout << "No" << endl;






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
