#include <iostream>

using namespace std;
typedef long long LL;

int main() {
    LL a, b, c, k;
    cin >> a >> b >> c >> k;
    if (k % 2 == 0) cout << a - b << endl;
    else cout << b - a << endl;

    return 0;
}