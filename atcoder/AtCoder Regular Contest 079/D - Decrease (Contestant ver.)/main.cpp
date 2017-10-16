#include <iostream>
using namespace std;
typedef long long LL;

int main() {
    LL k;
    scanf("%lld", &k);
    LL n = 50;
    LL base = k / n;
    int need = n - (k % n);
    cout << n << endl;
    for (int i = 0; i <= n; i++) {
        if (i == need) continue;
        cout << base + i << ' ';
    }
    cout << endl;

    return 0;
}