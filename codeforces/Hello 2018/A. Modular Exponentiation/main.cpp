#include <iostream>
using namespace std;
typedef long long LL;
int main() {
    LL n, m, ret;
    cin >> n >> m;
    if (n <= 32) ret = m % (1LL<<n);
    else ret = m;
    cout << ret << endl;
    return 0;
}