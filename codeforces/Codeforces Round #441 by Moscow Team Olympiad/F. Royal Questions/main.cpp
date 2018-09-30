#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 200000 + 10;

struct Item{
    int cost, a, b;
    bool operator< (const Item & other) const {
        return cost > other.cost;
    }
};
int dad[MAXN];
Item items[MAXN];
int find(int i) {
    if (dad[i] == i) return i;
    return dad[i] = find(dad[i]);
}
void add (int i, int j) {
    int a = find(i);
    int b = find(j);
    if (a > b) dad[a] = b;
    else dad[b] = a;
}
int main() {
//    freopen("test.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dad[i] = i;
    }
    int cost, a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &cost);
        items[i].cost = cost;
        items[i].a = a;
        items[i].b = b;
    }
    sort(items, items+m);
    int ret = 0;
    for (int i = 0; i < m; i++) {
        a = items[i].a;
        b = items[i].b;
        if (find(a) == find(b) && find(a) == 0) continue;
        ret += items[i].cost;
        if (find(a) == find(b)) {
            add(a, 0);
        }
        else add(a, b);
    }
    cout << ret << endl;


    return 0;
}