#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;
int b[MAXN];
int main() {
    int n, a;
    cin >> n;
    LL tot = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        tot += a;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d",&b[i]);
    }
    sort(b, b+n);
    LL ab = b[n-1] + b[n-2];
    if (tot > ab) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}