#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
typedef pair<int, int> pii;
int n, m, k;
const int MAXN = 10000 + 10;
vector<pii> col[MAXN];
vector<pii> row[MAXN];
int lights[MAXN][2];
int dis[MAXN];

int compute(int i, int j) {
    int x1 = lights[i][0], x2 = lights[i][1];
    int y1 = lights[j][0], y2 = lights[j][1];
    if (x1 == y1 && abs(x2-y2) <= 1) return 0;
    if (x2 == y2 && abs(x1-y1) <= 1) return 0;
    if (abs(x1-y1) <= 2) return 1;
    if (abs(x2-y2) <= 2) return 1;
    return -1;
}

void solve(priority_queue<pii, vector<pii>, greater<pii> > & pq, int id, int tmpid) {
    if (id == tmpid) return;
    int tmpval = compute(id, tmpid);
    if (tmpval == -1) return;
    if (tmpval+dis[id] < dis[tmpid]) {
        dis[tmpid] = tmpval + dis[id];
        pq.push({dis[tmpid], tmpid});
    }
}

void dijkstra(int start, int end) {
    fill(dis, dis+k, INT_MAX);
    dis[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int val = pq.top().first;
        int id = pq.top().second;
        pq.pop();
        if (id == end) return;
        if (dis[id] < val) continue;
        int x = lights[id][0], y = lights[id][1];
        for (int i = max(1, x-2); i <= min(lights[end][0], x+2); i++) {
            for (pii tmp : row[i]) {
                int tmpid = tmp.second;
                solve(pq, id, tmpid);
            }
        }
        for (int j = max(1, y-2); j <= min(lights[end][1], y+2); j++) {
            for (pii tmp : col[j]) {
                int tmpid = tmp.second;
                solve(pq, id, tmpid);
            }
        }


    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    bool flag = false;
    int a, b, start, end;
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &a, &b);
        row[a].push_back({b, i});
        col[b].push_back({a, i});
        lights[i][0] = a;
        lights[i][1] = b;
        if (a==n && b==m) {
            flag = true;
            end = i;
        }

        if (a==1 && b==1) start = i;

    }
    if (!flag) {
        row[n+1].push_back({m+1, k});
        col[m+1].push_back({n+1, k});
        lights[k][0] = n+1;
        lights[k][1] = m+1;
        end = k;
        k++;
    }
    dijkstra(start, end);
    if (dis[end] != INT_MAX) cout << dis[end] << endl;
    else cout << -1 << endl;
    return 0;
}