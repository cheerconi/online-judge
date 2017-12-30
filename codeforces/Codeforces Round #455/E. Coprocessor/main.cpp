#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1e5 + 10;
vector<int> edges[MAXN];
bool vis[MAXN], co[MAXN];
int degree[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> co[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edges[b].push_back(a);
        degree[a]++;
    }
    vector<int> v1, v2;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i] || degree[i] != 0) continue;
        if (co[i]) v2.push_back(i);
        else v1.push_back(i);
        vis[i] = true;
    }
    while (true) {
        for (int i = 0; i < v1.size(); i++) {
            int cur = v1[i];
            for (int son : edges[cur]) {
                if (vis[son]) continue;
                degree[son]--;
                if (degree[son] == 0) {
                    vis[son] = true;
                    if (co[son]) v2.push_back(son);
                    else v1.push_back(son);
                }
            }
        }
        v1.clear();
        bool flag = false;
        for (int i = 0; i < v2.size(); i++) {
            flag = true;
            int cur = v2[i];
            for (int son : edges[cur]) {
                if (vis[son]) continue;
                degree[son]--;
                if (degree[son] == 0) {
                    vis[son] = true;
                    if (co[son]) v2.push_back(son);
                    else v1.push_back(son);
                }
            }
        }
        v2.clear();
        if (flag) cnt++;
        else break;
    }
    cout << cnt << endl;


    return 0;
}