#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 3e5 + 10;
int vis[MAXN];
vector<pii> edges[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int n, m, d, tmp;
    scanf("%d%d%d", &n, &m, &d);
    queue<pii> q;
    for (int i = 0; i < m; i++) {
        scanf("%d", &tmp);
        if (vis[tmp] == 0) {
            vis[tmp] = tmp;
            q.push({tmp,tmp});
        }
    }
    int a, b;
    for (int i = 1; i <= n-1; i++) {
        scanf("%d%d", &a, &b);
        edges[a].push_back({b, i});
        edges[b].push_back({a, i});
    }
    set<int> ret;
    while (!q.empty()) {
        pii & cur = q.front();
        q.pop();
        for (auto & item : edges[cur.first]) {
            if (vis[item.first] == 0) {
                vis[item.first] = cur.second;
                q.push({item.first, cur.second});
            }
            else if (vis[item.first] != cur.second) {
                ret.insert(item.second);
            }
        }
    }
    cout << ret.size() << endl;
    auto it = ret.begin();
    for (int i = 0; i < ret.size(); i++) {
        printf("%d", *it++);
        if (i+1 == ret.size()) printf("\n");
        else printf(" ");
    }

}