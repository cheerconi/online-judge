#include <iostream>
using namespace std;
typedef long long LL;
int main() {
    LL n; cin >> n;
    n++;
    if (n % 2 == 0 || n == 1) cout << n/2 << endl;
    else cout << n << endl;

    return 0;
}