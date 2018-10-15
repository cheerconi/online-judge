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
typedef pair<pii, int> piii;
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
const int bias = 200;
const int MAXN = bias * 3 + 10;
vector<vector<int>> dx;
vector<vector<int>> dy;
vector<piii> edges[MAXN];
pii dist[MAXN];
int n, pos[MAXN];

bool update(int b, pii item, int u, int v) {
    if (dist[b].first == -1 || make_pair(item.first+u, item.second+v) < dist[b]) {
        dist[b] = make_pair(item.first+u, item.second+v);
        return true;
    }
    return false;
}

pii one_step(int a, int b) {
    memset(dist, -1, sizeof(dist));
    dist[a] = {0, 0};
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    pq.emplace(make_pair(0, 0), a);
    while (!pq.empty()) {
        auto item = pq.top(); pq.pop();
        assert(item.first.first >= 0 && item.first.second >= 0);
        if (dist[item.second] < item.first) continue;
        assert(dist[item.second] == item.first);
        int i = 0;
        while (item.second >= bias) {
            i++;
            item.second -= bias;
        }
        int x = item.second / n;
        int y = item.second % n;
        for (int k = 0; k < 3; k++) {
            if (i == k) continue;
            int bb = x*n + y + k * bias;
            if (update(bb, item.first, 1, 1)) pq.emplace(dist[bb], bb);
        }
        if (i == 0) {
            for (int j = 0; j < dx[0].size(); j++) {
                int xx = x + dx[0][j];
                int yy = y + dy[0][j];
                if (xx >= n || xx < 0) continue;
                if (yy >= n || yy < 0) continue;
                int bb = xx*n + yy;
                if (update(bb, item.first, 1, 0)) pq.emplace(dist[bb], bb);
            }
        } else {
            for (int j = 0; j < dx[i].size(); j++) {
                int len = 1;
                while (true) {
                    int xx = x + dx[i][j] * len;
                    int yy = y + dy[i][j] * len;
                    if (xx >= n || xx < 0) break;
                    if (yy >= n || yy < 0) break;
                    int bb = xx*n + yy + i * bias;
                    if (update(bb, item.first, 1, 0)) pq.emplace(dist[bb], bb);
                    len++;
                }
            }
        }
    }
    return dist[b];
}

pii solve(int a, int b) {
    memset(dist, -1, sizeof(dist));
    dist[a] = {0, 0};
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    pq.emplace(make_pair(0, 0), a);
    while (!pq.empty()) {
        auto item = pq.top(); pq.pop();
        assert(item.first.first >= 0 && item.first.second >= 0);
        if (dist[item.second] < item.first) continue;
        assert(dist[item.second] == item.first);
        for (auto nxt : edges[item.second]) {
            assert (nxt.first.first > 0);
            if (update(nxt.second, item.first, nxt.first.first, nxt.first.second)) {
                pq.emplace(dist[nxt.second], nxt.second);
            }
        }

    }
    return dist[b];
}






int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    dx.push_back(vector<int>{2, 2, -2, -2, 1, 1, -1, -1});
    dy.push_back(vector<int>{1, -1, 1, -1, 2, -2, 2, -2});
    dx.push_back(vector<int>{1, 1, -1, -1});
    dy.push_back(vector<int>{1, -1, -1, 1});
    dx.push_back(vector<int>{1, -1, 0, 0});
    dy.push_back(vector<int>{0, 0, 1, -1});
    cin >> n;
    int val;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> val;
            pos[val] = i*n + j;
        }
    }
    for (int i = 1; i+1 <= n*n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                auto d = one_step(pos[i]+j*bias, pos[i+1]+k*bias);
                assert(d.first > 0);
                edges[pos[i]+j*bias].emplace_back(d, pos[i+1]+k*bias);
            }
        }
    }
    pii ret = make_pair(INT_MAX, INT_MAX);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ret = min(solve(pos[1]+i*bias, pos[n*n]+bias*j), ret);
        }
    }
    cout << ret.first << ' ' << ret.second << endl;







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
