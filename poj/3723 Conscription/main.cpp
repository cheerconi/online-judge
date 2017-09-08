#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 20000 + 10;
const int MAXR = 70000 + 10;
const int val = 10000;
struct Edge{
    int a, b, c;
    bool operator< (Edge const & other) const {
        return c < other.c;
    }
};
Edge edges[MAXR];
int dad[MAXN];
void init (int n) {
    for (int i = 0; i <= n; i++) dad[i] = i;
}
int find(int i) {
    if (dad[i] == i) return i;
    return dad[i]=find(dad[i]);
}
void add(int i, int j) {
    int a = find(i);
    int b = find(j);
    if (a != b) dad[a] = dad[b];
}
bool check (int i, int j) {
    return find(i)==find(j);
}

int main() {
//    freopen("test.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--){
        int n, m, r;
        scanf("%d%d%d", &n, &m, &r);
        init(val+m);
        int a, b, c;
        for (int i = 0; i < r; i++) {
            scanf("%d%d%d", &a, &b, &c);
            edges[i].a = a;
            edges[i].b = b+val;
            edges[i].c = val - c;
        }
        for (int i = r; i < r+n; i++) {
            edges[i].a = i-r;
            edges[i].b = val+m;
            edges[i].c = val;
        }
        for (int i = r+n; i < r+n+m; i++) {
            edges[i].a = val+m;
            edges[i].b = i-r-n+val;
            edges[i].c = val;
        }
        sort(edges, edges+r+n+m);
        int cnt = 0;
        for (int i = 0; i < r+n+m; i++) {
            if (!check(edges[i].a, edges[i].b)) {
                cnt += edges[i].c;
                add(edges[i].a, edges[i].b);
            }
        }
        cout << cnt << endl;
    }

    return 0;
}