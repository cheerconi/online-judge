#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
int main() {
    LL n, k;
    cin >> n >> k;
    if (k == 0) {
        cout << n*n << endl;
        return 0;
    }
    LL ret = 0;
    for (LL b = k+1; b <= n; b++) {
        ret += (b-k) * (n / b);
        ret += max(0LL, n%b-k+1);
    }
    cout << ret << endl;
    return 0;
}