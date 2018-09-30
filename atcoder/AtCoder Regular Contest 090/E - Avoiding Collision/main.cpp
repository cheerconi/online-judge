#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pll;
const int MAXN = 100000 + 10;
const int mod = 1e9 + 7;
const LL inf = (1LL<<63) - 1;
int n;
LL dists[MAXN], distt[MAXN], cnts[MAXN], cntt[MAXN];
vector<pll> edges[MAXN];

void dijkstra(LL dist[], LL cnt[], LL s, LL t) {
    for (int i = 1; i <= n; i++) {
        dist[i] = inf;
    }
    dist[s] = 0;
    cnt[s] = 1;
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    pq.push({0LL, s});
    while (!pq.empty()) {
        pll cur = pq.top(); pq.pop();
        if (cur.first > dist[cur.second]) continue;
        if (cur.second == t) return;
        for (auto nxt : edges[cur.second]) {
            if (cur.first+nxt.second < dist[nxt.first]) {
                dist[nxt.first] = cur.first + nxt.second;
                pq.push({dist[nxt.first], nxt.first});
                cnt[nxt.first] = cnt[cur.second] % mod;
            }
            else if (cur.first+nxt.second == dist[nxt.first]) {
                cnt[nxt.first] = (cnt[nxt.first] + cnt[cur.second]) % mod;
            }
        }
    }
}

int main(){
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m, s, t;
    cin >> n >> m >> s >> t;
    LL a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    dijkstra(dists, cnts, s, t);
    dijkstra(distt, cntt, t, s);
    double half = dists[t] / 2.0;
    LL ret = cnts[t] * cnts[t] % mod;
    for (int i = 1; i <= n; i++) {
        if (dists[i] == half) {
            LL tmp = cnts[i] * cntt[i] % mod;
            ret = (ret + mod - tmp*tmp%mod) % mod;
        }
        for (auto item : edges[i]) {
            int j = item.first;
            if (dists[i]+item.second+distt[j] != dists[t]) continue;
            if (dists[i]<half && dists[j] > half) {
                LL tmp = cnts[i] * cntt[j] % mod;
                ret = (ret + mod - tmp*tmp%mod) % mod;
            }
        }
    }
    cout << ret << endl;


}