#include <iostream>
#include <vector>
#include <memory.h>
#include <limits.h>
#include <algorithm>
using namespace std;
const int MAXN = 200 + 10;
const int MAXV = 2e4 + 10;
struct Edge{
    int to, rev, pip;
};
vector<Edge> edges[MAXN];
int nums[MAXN];
bool isprime[MAXV], vis[MAXN];

void add_edge(int x, int y, int val) {
    Edge item;
    item.to = y;
    item.pip = val;
    item.rev = edges[y].size();
    edges[x].push_back(item);
    item.to = x;
    item.pip = 0;
    item.rev = edges[x].size()-1;
    edges[y].push_back(item);
}

void build (int n) {
    memset(isprime, true, sizeof(isprime));
    for (int i = 2; i < MAXV; i++) {
        if (isprime[i]) {
            for (int j = i*i; j < MAXV; j += i) {
                isprime[j] = false;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (nums[i] % 2 != 0) {
            add_edge(0, i, 2);
            for (int j = 1; j <= n; j++) {
                if (isprime[nums[i]+nums[j]]) add_edge(i, j, 1);
            }
        }
        else add_edge(i, n+1, 2);
    }
}
int dfs(int cur, int f, int sink) {
    if (f == 0 || cur == sink) return f;
    vis[cur] = true;
    for (auto & item : edges[cur]) {
        if (!vis[item.to]){
            int tmp = dfs(item.to, min(f, item.pip), sink);
            if (tmp > 0) {
                item.pip -= tmp;
                edges[item.to][item.rev].pip += tmp;
                return tmp;
            }
        }
    }
    return 0;
}
void print(int n) {
    vector<vector<int> > vs;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vs.push_back(vector<int>());
        int cur = i;
        while (true) {
            bool delta = false;
            vs.back().push_back(cur);
            vis[cur] = true;
            for (auto item : edges[cur]) {
                if(vis[item.to] || item.to == 0 || item.to == n+1) continue;
                if (nums[cur]%2 == 1 && item.pip == 0) {
                    cur = item.to;
                    delta = true;
                    break;
                }
                else if (nums[cur]%2 == 0 && item.pip == 1) {
                    cur = item.to;
                    delta = true;
                    break;
                }
            }
            if (!delta) break;
        }
    }
    cout << vs.size() << endl;
    for (auto & v : vs) {
        cout << v.size();
        for (int i = 0; i < v.size(); i++) {
            cout <<' ' << v[i];
        }
        cout << endl;
    }
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    if (n % 2 != 0) {
        cout << "Impossible" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    build(n);
    int ret = 0;
    while (true) {
        int f = dfs(0, INT_MAX, n+1);
        memset(vis, false, sizeof(vis));
        if (f == 0) break;
        ret += f;
    }
    if (ret != n) {
        cout << "Impossible" << endl;
        return 0;
    }
    print(n);

    return 0;
}