#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 200000 + 10;
int a[MAXN], b[MAXN], ind[MAXN], ret[MAXN];
bool cmp(int i, int j) {
    return b[i] > b[j];
}
int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        ind[i] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    sort(ind, ind+n, cmp);
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        ret[ind[i]] = a[i];
    }
    for (int i = 0; i < n; i++) {
        printf("%d", ret[i]);
        if (i == n-1) cout << endl;
        else printf(" ");
    }

    return 0;
}