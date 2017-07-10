#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

int main() {
//    freopen("test.txt", "r", stdin);
    int n, a, b, c, d;
    scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
    b = abs(b - a);
    bool flag = false;
    for (LL i = 0; i < n; i++) {
        LL left = c * (n - 1 - i) - d * i;
        LL right = d * (n - 1 - i) - c * i;
        if (left <= b && b <= right) {
            flag = true;
            break;
        }

    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;

}