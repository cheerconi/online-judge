#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <ctime>
#include <deque>
#include <functional>
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
const int MAXN = 1000 + 10;
vi edges[MAXN], nodes;
bool dead[MAXN];
int sz[MAXN], n;
int ask(const vector<int>& nums) {
    assert(nums.size() >= 2);
    static int cnt = 12;
    cnt--;
    assert(cnt >= 0);
    cout << "? " << nums.size();
    for (int num : nums) {
        cout << " " << num;
    }
    cout << endl;
    int val; cin >> val;
    return val;
}

void answer(int a, int b) {
    cout << "! " << a << ' ' << b << endl;
}

void dfs(int cur, int par) {
    sz[cur] = 1;
    for (int nxt : edges[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur);
        sz[cur] += sz[nxt];
    }
}

pii find() {
    int par = -1;
    int son = -1;
    int diff = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (dead[i]) continue;
        dfs(i, -1);
        for (int nxt : edges[i]) {
            int tmp = abs(sz[i] - 2 * sz[nxt] - 2);
            if (tmp < diff) {
                diff = tmp;
                par = i;
                son = nxt;
            }
        }
    }
    assert(par != -1);
    return {par, son};
}

void collect(int cur, int par, function<void(int)> f) {
    f(cur);
    for (int nxt : edges[cur]) {
        if (nxt == par) continue;
        collect(nxt, cur, f);
    }
}

void clean() {
    for (int i = 1; i <= n; i++) {
        if (dead[i]) {
            edges[i].clear();
            continue;
        }
        for (int j = 0; j < edges[i].size(); j++) {
            if (dead[edges[i][j]]) {
               swap(edges[i][j], edges[i].back());
               edges[i].pop_back();
               j--;
            }
        }
    }
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
//  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vi nums(n);
    iota(nums.begin(), nums.end(), 1);
    int ret = ask(nums);
    while (true) {
        auto [par, son] = find();
        dfs(par, -1);
        if (sz[par] == 2) {
            answer(par, son);
            return 0;
        }
        nodes.clear();
        collect(son, par, [](int cur){nodes.push_back(cur);});
        nodes.push_back(par);
        int cur = ask(nodes);
        if(cur == ret) {
            if (nodes.size() == 2) {
                answer(nodes[0], nodes[1]);
                return 0;
            }
            for (int nxt : edges[par]) {
                if (nxt == son) continue;
                collect(nxt, par, [](int cur){dead[cur] = true;});
            }
        } else {
            collect(son, par, [](int cur){dead[cur]=true;});
        }
        clean();
    }










/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
