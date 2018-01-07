#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
int main() {
    LL a, b, x, y, z;
    cin >> a >> b >> x >> y >> z;
    LL A = 2*x + y;
    LL B = y + 3*z;
    LL ret = max(0LL, A - a) + max(0LL, B - b);
    cout << ret << endl;

    return 0;
}