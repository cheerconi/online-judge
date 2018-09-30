#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 2e5 + 10;
bool live[MAXN];
vector<int> edges[MAXN];
vector<int> ret;

void dfs2(int cur) {
    ret.push_back(cur);
    live[cur] = false;
    for (int nxt : edges[cur]) {
        if (live[nxt]) dfs2(nxt);
    }
}

void dfs1(int cur) {
    int cnt = 0;
    for (int nxt : edges[cur]) {
        dfs1(nxt);
        if (live[nxt]) cnt++;
    }
    if (cnt % 2 == 1) {
        dfs2(cur);
    }
}


int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        live[i] = true;
    }
    int root, par;
    for (int i = 1; i <= n; i++) {
        cin >> par;
        if (par == 0) root = i;
        else edges[par].push_back(i);
    }
    dfs1(root);
    if (!live[root]) {
        cout << "NO" << endl;
        return 0;
    }
    dfs2(root);
    cout << "YES" << endl;
    for (int num : ret) {
        cout << num << '\n';
    }

    return 0;
}