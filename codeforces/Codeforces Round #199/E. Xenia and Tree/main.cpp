#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
vector<int> edges[MAXN];
int deep[MAXN], dist[MAXN], ancester[MAXN][10];
bool inq[MAXN];
void dfs (int root, int par) {
    if (par != 0) {
        dist[root] = deep[root] = deep[par]+1;
    }
    ancester[root][0] = par;
    for (int son : edges[root]) {
        if (son != par) dfs(son, root);
    }
}
int solve(int a, int b) {
    if (deep[a] < deep[b]) swap(a, b);
    int ret = 0;
    while (deep[a] > deep[b]) {
        int i = 0;
        while (i < 9 && deep[a]-(1<<(i+1))>=deep[b]) i++;
        a = ancester[a][i];
        ret += 1<<i;
    }
    while (a != b) {
        if (ancester[a][0] == ancester[b][0]) {
            ret += 2;
            break;
        }
        int i = 0;
        while (i < 9 && ancester[a][i] != ancester[b][i]) i++;
        i--;
        a = ancester[a][i];
        b = ancester[b][i];
        ret += (1<<(i+1));
    }
    return ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1, 0);
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j <= n; j++) {
            ancester[j][i] = ancester[ancester[j][i-1]][i-1];
        }
    }
    unordered_set<int> table;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        if (a == 1) {
            table.insert(b);
            dist[b] = 0;
            if (table.size() == 90) {
                queue<int> q;
                for (int item : table) {
                    q.push(item);
                    inq[item] = true;
                }
                table.clear();
                while (!q.empty()) {
                    a = q.front();
                    q.pop();
                    inq[a] = false;
                    for (int son : edges[a]) {
                        if (dist[son] > dist[a] + 1) {
                            dist[son] = dist[a] + 1;
                            if (!inq[son]) {
                                q.push(son);
                                inq[son] = true;
                            }
                        }
                    }
                }
            }
        }
        else {
            int ret = dist[b];
            for (int item : table) {
                ret = min(ret, solve(item, b));
            }
            printf("%d\n", ret);
        }
    }

    return 0;
}