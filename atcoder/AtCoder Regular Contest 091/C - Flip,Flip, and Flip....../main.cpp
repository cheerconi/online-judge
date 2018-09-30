#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
LL solve (LL n, LL m) {
    if (n == 1) {
        if (m == 1) return 1;
        return m-2;
    }
    if (n == 2) {
        return 0;
    }
    return (n-2)*(m-2);
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << solve (min(n, m), max(n, m));

    return 0;
}