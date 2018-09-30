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
struct Robot{
    int x, r, q;
    Robot(int _x, int _r, int _q) {
        x = _x;
        r = _r;
        q = _q;
    }
    bool operator< (const Robot& rhs) const {
        return x-r < rhs.x-rhs.r;
    }
};
const int MAXN = 3e5 + 10;
int L[MAXN*20], R[MAXN*20], tree[MAXN*20], tot;

bool cmp(const Robot& r1, const Robot& r2) {
    return r1.x < r2.x;
}

int update(int node, int left, int right, int i) {
    tot++;
    int nxt_node = tot;
    if (left != right) {
        int mid = (left+right) >> 1;
        if (i > mid) {
            R[nxt_node] = update(R[node], mid+1, right, i);
            L[nxt_node] = L[node];
        }
        else {
            L[nxt_node] = update(L[node], left, mid, i);
            R[nxt_node] = R[node];
        }
    }
    tree[nxt_node] = tree[node]+1;
    return nxt_node;
}

int query(int node, int left, int right, int i, int j) {
    if (j < left || right < i) return 0;
    if (i <= left && right <= j) {
        return tree[node];
    }
    int mid = (left+right) >> 1;
    int ret = query(L[node], left, mid, i, j) + query(R[node], mid+1, right, i, j);
    return ret;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n, k, x, r, q;
    cin >> n >> k;
    vector<Robot> items, robots;
    map<int, int> qs;
    vector<int> tmp;
    for (int i = 0; i < n; i++) {
        cin >> x >> r >> q;
        items.emplace_back(x, r, q);
        robots.emplace_back(x, r, q);
        tmp.push_back(x);
        tmp.push_back(x+r);
        tmp.push_back(x-r);
        qs[q] = 0;
    }
    sort(tmp.begin(), tmp.end());
    tmp.resize(unique(tmp.begin(), tmp.end())- tmp.begin());
    unordered_map<int, int> g2lo;
    int idx = 1;
    for (int num : tmp) {
        g2lo[num] = idx++;
    }
    int nn = idx-1;
    sort(items.begin(), items.end());
    sort(robots.begin(), robots.end(), cmp);
    idx = 0;
    LL ret = 0;
    for (auto& robot : robots) {
        while (idx < n && items[idx].x-items[idx].r <= robot.x) {
            qs[items[idx].q] = update(qs[items[idx].q], 1, nn, g2lo[items[idx].x]);
            idx++;
        }
        auto it = qs.upper_bound(robot.q+k);
        if (it == qs.begin()) continue;
        int a = g2lo[robot.x];
        int b = g2lo[robot.x+robot.r];
        do {
            it--;
            if (it->first < robot.q-k) break;
            ret += query(it->second, 1, nn, a, b);
        } while (it != qs.begin());
    }
    tmp.clear();
    int cur = robots[0].x;
    for (int i = 0; i < n; i++) {
        if (cur == robots[i].x) {
            tmp.push_back(robots[i].q);
        }
        else {
            idx = 0;
            sort(tmp.begin(), tmp.end());
            for (int j = 0; j < tmp.size(); j++) {
                idx = max(idx, j);
                while (idx < tmp.size() && tmp[idx]-tmp[j] <= k) idx++;
                ret -= idx - j;
            }
            cur = robots[i].x;
            tmp.clear();
            tmp.push_back(robots[i].q);
        }
    }
    idx = 0;
    sort(tmp.begin(), tmp.end());
    for (int j = 0; j < tmp.size(); j++) {
        idx = max(idx, j);
        while (idx < tmp.size() && tmp[idx]-tmp[j] <= k) idx++;
        ret -= idx - j;
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
