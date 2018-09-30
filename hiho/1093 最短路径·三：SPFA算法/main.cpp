#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 1e5 + 10;
vector<int> edges[MAXN];
vector<int> costs[MAXN];
int dis[MAXN];
bool inq[MAXN];
int n;

void spfa(int s) {
    fill(dis+1, dis+n+1, INT_MAX);
    memset(inq, false, sizeof(inq));
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    inq[s] = true;
    while(!q.empty()) {
        int node = q.front();
        int val = dis[node];
        q.pop();
        inq[node] = false;
        for (int i = 0; i < edges[node].size(); i++) {
            int son = edges[node][i];
            if (dis[son] > val + costs[node][i]) {
                dis[son] = val + costs[node][i];
                if (!inq[son]) {
                    q.push(son);
                    inq[son] = true;
                }
            }
        }
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    int m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        edges[a].push_back(b);
        edges[b].push_back(a);
        costs[a].push_back(c);
        costs[b].push_back(c);
    }
    spfa(s);
    cout << dis[t] << endl;
    return 0;
}