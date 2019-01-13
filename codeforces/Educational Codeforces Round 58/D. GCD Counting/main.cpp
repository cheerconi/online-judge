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
int factor[MAXN], data[MAXN][2], nums[MAXN], cur;
vector<int> edges[MAXN];
vector<int> ps;
unordered_map<int, int> table;
bool vis[MAXN];
void init() {
    for (LL i = 2;  i < MAXN; i++) {
        if (factor[i] != 0) continue;
        ps.push_back(i);
        for (LL j = i*i; j < MAXN; j += i) {
            factor[j] = i;
        }
    }
}

int dfs(int root, int par) {
    vis[root] = true;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int nxt : edges[root]) {
        if (nxt == par) continue;
        pq.push(dfs(nxt, root));
        if (pq.size() > 2) pq.pop();
    }
    int sum = 1, ret = 1;
    while (!pq.empty()) {
        sum += pq.top();
        ret = max(ret, 1 + pq.top());
        pq.pop();
    }
    cur = max(cur, sum);
    return ret;
}


int solve(int p, int n) {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        edges[i].clear();
    }
    for (int i = 0; i < n-1; i++) {
        if (nums[data[i][0]]%p != 0 || nums[data[i][1]]%p != 0) continue;
        edges[data[i][0]].push_back(data[i][1]);
        edges[data[i][1]].push_back(data[i][0]);
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] || nums[i]%p != 0) continue;
        cur = 0;
        dfs(i, 0);
        ret = max(ret, cur);
    }
    return ret;
}





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    init();
    int n, val;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val;
        nums[i] = val;
        while (factor[val] != 0) {
            int tmp = factor[val];
            table[tmp]++;
            while (val % tmp == 0) val /= tmp;
        }
        if (val != 1) table[val]++;
    }
    for (int i = 0; i < n-1; i++) {
        cin >> data[i][0] >> data[i][1];
    }
    int ret = 0;
    for (int p : ps) {
        if (table[p] > ret) ret = max(solve(p, n), ret);
    }
    cout << ret << endl;





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
