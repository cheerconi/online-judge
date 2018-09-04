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
int nums[MAXN], cnt[MAXN], par[MAXN];
vector<int> edges[MAXN];

void dfs(int cur, int p) {
    par[cur] = p;
    cnt[p]++;
    for (int nxt : edges[cur]) {
        if (nxt == p) continue;
        dfs(nxt, cur);
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
    int a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    dfs(1, 0);
    queue<int> q;
    q.push(0);
    bool flag = true;
    int i = 0;
    while (i < n && flag) {
        if (q.empty()) {
            flag = false;
            break;
        }
        int cur = q.front(); q.pop();
        for (int j = 0; j < cnt[cur] && flag; j++) {
            if (i >= n || par[nums[i]] != cur) {
                flag = false;
                break;
            }
            q.push(nums[i]);
            i++;
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
