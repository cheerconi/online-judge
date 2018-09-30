#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int MAXN = 200000 + 10;
vector<int> edges[MAXN], cad;
bool todo[MAXN];
int n, par[MAXN];

int find(int i) {
    if (par[i] == i) return i;
    return par[i] = find(par[i]);
}
void add (int i, int j) {
    int a = find(i);
    int b = find(j);
    par[a] = b;
}
int check() {
    int idx = 1;
    for (int i = 2; i <= n; i++) {
        if (edges[i].size() < edges[idx].size()) {
            idx = i;
        }
    }
    if (edges[idx].empty()) {
        cout << 1 << endl << n << endl;
        exit(0);
    }
    for (int i : edges[idx]) {
        todo[i] = true;
        cad.push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (!todo[i]) add(i, idx);
    }
    return idx;
}


int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sort(edges[i].begin(), edges[i].end());
    }
    int idx = check();
    for (int i = 0; i < cad.size(); i++) {
        for (int j = i+1; j < cad.size(); j++) {
            auto it = lower_bound(edges[cad[j]].begin(), edges[cad[j]].end(), cad[i]);
            if (it == edges[cad[j]].end() || *it != cad[i]) add (cad[i], cad[j]);
        }
    }
    for (int i : cad) {
        if (find(i) == find(idx)) continue;
        if (edges[i].size() < n-cad.size()) {
            add (i, idx);
            continue;
        }
        for (int j = 1; j <= n; j++) {
            if (todo[j]) continue;
            auto it = lower_bound(edges[i].begin(), edges[i].end(), j);
            if (it == edges[i].end() || *it != j) {
                add (i, j);
                break;
            }
        }
    }
    unordered_map<int, int> ret;
    for (int i = 1; i <= n; i++) {
        ret[find(i)]++;
    }
    cout << ret.size() << endl;
    vector<int> v;
    for (auto it = ret.begin(); it != ret.end(); it++) {
        v.push_back(it->second);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i+1 == ret.size()) cout << endl;
        else cout << ' ';
    }
    return 0;

}