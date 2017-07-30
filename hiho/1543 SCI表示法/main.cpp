#include <iostream>
using namespace std;
typedef long long LL;

bool check(LL d, LL n) {
    n = n << 1;
    if (n % d != 0) return false;
    n = n / d + 1 - d;
    if (n & 1) return false;
    n = n >> 1;
    if (n > 0) return true;
    return false;

}

int main() {
//    freopen("test.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int ret = 0;
        for (int i = 1; i*i + i <= 2*n; i++) {
            if (check(i, n)) ret = i;
        }
        printf("%d\n", ret);

    }
}