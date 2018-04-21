#include <iostream>
#include <algorithm>
using namespace std;
int main() {
//    freopen("test.txt", "r", stdin);
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ret = x*a + y*b;
    ret = min(ret, max(x,y)*2*c);
    if (x > y) {
        ret = min(ret, 2*y*c + (x-y)*a);
    }
    else if (y > x) {
        ret = min(ret, 2*x*c + (y-x)*b);
    }
    cout << ret << endl;

    return 0;
}