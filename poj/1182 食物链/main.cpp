#include <iostream>
using namespace std;
const int MAXN = 50000 + 10;
int dad[MAXN*3];
int n, k;
int a, i, j;

int find(int i) {
    if (dad[i] == i) return i;
     return dad[i] = find(dad[i]);

}
void unite(int i, int j) {
    int x = find(i);
    int y = find(j);
    if (x == y) return;
    dad[x] = y;
}

bool solve() {
    if (i > n || j > n) return false;
    int x1 = find(i), y1 = find(j);
    int x2 = find(i+n), y2 = find(j+n);
    int x3 = find(i+2*n), y3 = find(j+2*n);
    if (a == 1) {
        if (x1 == y2 || x1 == y3 || y1 == x2 || y1 == x3 || x2 == y3 || x3 == y2) return false;
        unite(x1, y1);
        unite(x2, y2);
        unite(x3, y3);
        return true;
    }
    else {
        if (x1 == y1 || x1 == y3 || x2 == y2 || x2 == y1 || x3 == y3 || x3 == y2) return false;
        unite(x1, y2);
        unite(x2, y3);
        unite(x3, y1);
        return true;
    }

}

int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    int cnt = 0;
    for (int i = 1; i <= 3*n; i++) dad[i] = i;
    while (k--) {
        scanf("%d%d%d", &a, &i, &j);
        if (!solve()) cnt++;
    }
    cout << cnt << endl;
    return 0;
}