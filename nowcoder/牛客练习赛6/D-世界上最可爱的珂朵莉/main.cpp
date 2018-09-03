#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 200000 + 10;
int a[MAXN], b[MAXN];
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    sort(a, a+n);
    sort(b, b+n);
    for (int i = 0; i < min(n, x); i++) {
        if (a[i] < y) a[i] = y;
        else break;
    }
    sort(a, a+n);
    int ret = 0;
    for (int i = 0; i < n; i++) {
        ret = max(ret, b[i]-a[i]);
    }
    cout << ret << endl;

    return 0;
}