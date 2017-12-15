#include <iostream>
#include <unordered_set>
using namespace std;
const int MAXN = 100000 + 10;
int par[MAXN];

int find(int i) {
    if (par[i] == i) return i;
    return par[i] = find(par[i]);
}
void add (int i, int j) {
    int a = find(i);
    int b = find(j);
    par[a] = b;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    unordered_set<int> table;
    for (int i = 1; i <= n; i++) {
        table.insert(find(i));
    }
    cout << table.size() - 1 << endl;

    return 0;
}