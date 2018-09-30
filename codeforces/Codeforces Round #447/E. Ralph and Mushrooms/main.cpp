#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
const int MAXN = 1e6 + 10;
int tag[MAXN];
vector<pii> edges[MAXN], n_edges[MAXN];
int cur_clock = 1;
int scc[MAXN], scc_id = 1;
stack<int> s;
LL dp[MAXN], node[MAXN];

inline int read() {
    register int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int tarjan(int cur) {
    s.push(cur);
    tag[cur] = cur_clock++;
    int ret = tag[cur];
    for (pii son : edges[cur]) {
        int x = son.first;
        if (tag[x] == 0) {
            ret = min(ret, tarjan(x));
        }
        else if (scc[x] == 0) {

            ret = min(ret, tag[x]);
        }
    }
    if (ret == tag[cur]) {
        while (s.top() != cur) {
            scc[s.top()] = scc_id;
            s.pop();
        }
        scc[cur] = scc_id++;
        s.pop();
    }
    return ret;
}
LL calc(int x) {
    LL left = 0, right = 5e4;
    while (left < right) {
        LL mid = (left+right+1) >> 1;
        if (x < mid*(mid+1)/2) right = mid-1;
        else left = mid;
    }
    LL ret = (left+1) * x;
    ret -= (left*(left+1)*(left+2)) / 6;
    return ret;
}

LL solve (int x) {
    if (dp[x] != -1) return dp[x];
    LL ret = node[x];
    for (pii item : n_edges[x]) {
        int y = item.first;
        int val = item.second;
        ret = max(ret, solve(y)+val+node[x]);
    }
    dp[x] = ret;
    return ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, m;
    n = read(), m = read();
    int a, b, val;
    for (int i = 0; i < m; i++) {
        a = read(), b = read(), val = read();
        edges[a].push_back({b, val});
    }
    m = read();
    tarjan(m);
    for (int x = 1; x <= n; x++) {
        if (tag[x] == 0) continue;
        for (pii item : edges[x]) {
            int y = item.first;
            val = item.second;
            if (scc[x] == scc[y]) {
                node[scc[x]] += calc(val);
            }
            else{
                n_edges[scc[x]].push_back({scc[y], val});
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(scc[m]) << endl;

    return 0;
}