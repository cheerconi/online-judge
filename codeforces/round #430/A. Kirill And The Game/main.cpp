#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int main() {
//    freopen("test.txt", "r", stdin);
    int l, r, x, y, k;
    scanf("%d%d%d%d%d", &l, &r, &x, &y, &k);
    bool flag = false;
    for (LL i = x; i <= y; i++) {
        LL tmp = k * i;
        if (tmp >= l && tmp <= r) {
            flag = true;
            break;
        }
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}