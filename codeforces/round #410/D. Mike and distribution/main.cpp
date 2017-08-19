#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
int a[MAXN], b[MAXN], ind[MAXN];

bool cmp(int i, int j) {
    return a[i] > a[j];
}
int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        ind[i] = i;
    }
    sort(ind, ind+n, cmp);
    int cnt = n/2 + 1;
    int i = 0;
    printf("%d\n%d", cnt, ind[i++]+1);
    if (n % 2 == 0) printf(" %d", ind[i++]+1);
    if (i == cnt-1) {
        cout << endl;
        return 0;
    }
    printf(" ");
    for (; i < n; i += 2) {
        if (b[ind[i]] > b[ind[i+1]]) printf("%d", ind[i]+1);
        else printf("%d", ind[i+1]+1);
        if (i+2 == n) cout << endl;
        else cout << ' ';
    }
    return 0;
}