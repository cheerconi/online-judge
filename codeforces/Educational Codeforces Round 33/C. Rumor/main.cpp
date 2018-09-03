#include <iostream>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
int dad[MAXN], cost[MAXN];

int find(int i) {
    if (dad[i] == i) return i;
    return dad[i] = find(dad[i]);
}
void add(int i, int j) {
    int a = find(i);
    int b = find(j);
    if (cost[a] > cost[b]) {
        dad[a] = b;
    }
    else dad[b] = a;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dad[i] = i;
        scanf("%d", &cost[i]);
    }
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    LL ret = 0;
    for (int i = 1; i <= n; i++) {
        ret += cost[find(i)];
        cost[find(i)] = 0;
    }
    cout << ret << endl;


    return 0;
}