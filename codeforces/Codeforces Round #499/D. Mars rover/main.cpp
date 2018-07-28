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
const int MAXN = 1e6 + 10;
vector<int> edges[MAXN];
char op[MAXN];
bool ret[MAXN], node[MAXN];

void dfs(int cur) {
    if (op[cur] == 'I') return;
    for (int nxt : edges[cur]) {
        dfs(nxt);
    }
    if (op[cur] == 'N') {
        node[cur] = !node[edges[cur][0]];
    }
    else if (op[cur] == 'A') {
        node[cur] = node[edges[cur][0]] && node[edges[cur][1]];
    }
    else if (op[cur] == 'O') {
        node[cur] = node[edges[cur][0]] || node[edges[cur][1]];
    }
    else if (op[cur] == 'X') {
        node[cur] = node[edges[cur][0]] ^ node[edges[cur][1]];
    }
}

void solve(int cur) {
    if (op[cur] == 'I') {
        ret[cur] = !ret[cur];
        return;
    }
    if (op[cur] == 'A') {
        if (node[edges[cur][1]]) solve(edges[cur][0]);
        if (node[edges[cur][0]]) solve(edges[cur][1]);
    }
    else if (op[cur] == 'O') {
        if (!node[edges[cur][1]]) solve(edges[cur][0]);
        if (!node[edges[cur][0]]) solve(edges[cur][1]);
    }
    else if (op[cur] == 'X') {
        solve(edges[cur][0]);
        solve(edges[cur][1]);
    }
    else if (op[cur] == 'N') {
        solve(edges[cur][0]);
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
    int n; cin >> n;
    string s;
    int a, b;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        op[i] = s[0];
        if (s[0] == 'A' || s[0] == 'X' || s[0] == 'O') {
            cin >> a >> b;
            edges[i].push_back(a);
            edges[i].push_back(b);
        }
        else {
            cin >> a;
            if (s[0] == 'I') {
                node[i] = a;
            }
            else edges[i].push_back(a);
        }
    }
    dfs(1);
    for (int i = 1; i <= n; i++) ret[i] = node[1];
    solve(1);
    for (int i = 1; i <= n; i++) {
        if (op[i] == 'I') cout << ret[i];
    }
    cout << endl;




/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
