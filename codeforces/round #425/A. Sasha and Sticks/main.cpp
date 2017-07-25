#include <iostream>
using namespace std;
typedef long long LL;

int main() {
    LL n, k;
    cin >> n >> k;
    LL ret = n / k;
    if (ret & 1LL == 1) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

    return 0;
}