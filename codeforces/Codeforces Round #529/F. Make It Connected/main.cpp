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
typedef pair<LL, int> pli;
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
constexpr int MAXN = 2e5 + 10;
int par[MAXN];
LL nums[MAXN];
int find(int i) {
    if (par[i] == i) return i;
    return par[i]=find(par[i]);
}
void add(int i, int j) {
    int a = find(i);
    int b = find(j);
    if (nums[a] > nums[b]) par[a] = b;
    else par[b] = a;
}
struct Item{
    int a, b;
    LL val;
    Item(int a_, int b_, LL val_): a(a_), b(b_), val(val_) {}
    bool operator<(const Item& rhs) const {
        return val > rhs.val;
    }

};





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n, m, a, b;
    LL val;
    cin >> n >> m;
    vector<pli> ps;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        ps.emplace_back(nums[i], i);
        par[i] = i;
    }
    vector<Item> edges;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> val;
        edges.emplace_back(a-1, b-1, val);
    }
    sort(edges.begin(), edges.end());
    sort(ps.begin(), ps.end(), greater<>());

    LL ret = 0;
    while (ps.size() >= 2) {
        int sz = (int)ps.size() - 1;
        a = find(ps[sz].second);
        b = find(ps[sz-1].second);
        if (a == b) {
            ps.pop_back();
            ps.back() = {nums[a], a};
            continue;
        }
        while (!edges.empty() && find(edges.back().a) == find(edges.back().b)) {
            edges.pop_back();
        }

        LL tmp = nums[a] + nums[b];

        if (!edges.empty() && edges.back().val < tmp) {
            ret += edges.back().val;
            add(edges.back().a, edges.back().b);
            edges.pop_back();
        } else {
            ret += tmp;
            add(a, b);
            ps.pop_back();
            a = find(a);
            ps.back() = {nums[a], a};
        }
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
