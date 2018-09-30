#include <iostream>
using namespace std;
typedef long long LL;
int main() {
    LL x, y;
    cin >> x >> y;
    if (x % y == 0) cout << -1 << endl;
    else cout << x*(y+1) << endl;

    return 0;
}