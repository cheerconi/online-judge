#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1000 + 10;
vector<int> edges[MAXN];
int dfs(int cur) {
    int sz = 0, leaf = 0;
    for (int son : edges[cur]) {
        int tmp = dfs(son);
        if (tmp == -1) return -1;
        sz++;
        if (tmp == 0) leaf++;
    }
    if (sz == 0) return 0;
    if (leaf >= 3) return 1;
    return -1;
}
int main() {
    int n; cin >> n;
    int par;
    for (int i = 2; i <= n; i++) {
        cin >> par;
        edges[par].push_back(i);
    }
    if (dfs(1) != -1) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}