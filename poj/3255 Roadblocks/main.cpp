#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <vector>
#include <limits.h>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 5000 + 10;
int dis[MAXN];
int dis2[MAXN];
int n;
vector<pii> edges[MAXN];
int solve() {
    memset(dis, -1, sizeof(dis));
    dis[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(0, 1));
    while (!pq.empty()) {
        pii item = pq.top();
        pq.pop();
        if (dis[item.second] < item.first) continue;
        for (int i = 0; i < edges[item.second].size(); i++) {
            pii tmp = edges[item.second][i];
            if (dis[tmp.second]==-1 || dis[item.second]+tmp.first < dis[tmp.second]) {
                dis[tmp.second] = dis[item.second] + tmp.first;
                pq.push(make_pair(dis[tmp.second], tmp.second));
            }
        }
    }
    memset(dis2, -1, sizeof(dis));
    dis2[n] = 0;
    pq.push(make_pair(0, n));
    while (!pq.empty()) {
        pii item = pq.top();
        pq.pop();
        if (dis2[item.second] < item.first) continue;
        for (int i = 0; i < edges[item.second].size(); i++) {
            pii tmp = edges[item.second][i];
            if (dis2[tmp.second]==-1 || dis2[item.second]+tmp.first < dis2[tmp.second]) {
                dis2[tmp.second] = dis2[item.second] + tmp.first;
                pq.push(make_pair(dis2[tmp.second], tmp.second));
            }
        }
    }
//    for (int i = 1; i <= n; i++) cout << dis[i] <<' ';
//    cout << endl;
//    for (int i = 1; i <= n; i++) cout << dis2[i] <<' ';
//    cout << endl;
    int ret = INT_MAX;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < edges[i].size(); j++) {
            pii item = edges[i][j];
            int tmp = dis[i]+item.first + dis2[item.second];
            if (dis[n] == tmp) {
                ret = min(ret, dis[n]+2*item.first);
            }
            else ret = min(ret, tmp);
        }
    }

    return ret;


 }
int main() {
//    freopen("test.txt", "r", stdin);
    int r, a, b, c;
    scanf("%d%d", &n, &r);
    for (int i = 0; i < r; i++) {
        scanf("%d%d%d", &a, &b, &c);
        edges[a].push_back(make_pair(c, b));
        edges[b].push_back(make_pair(c, a));
    }
    cout << solve() << endl;

    return 0;
}