#include <iostream>
using namespace std;
int main() {
    int d, t, v1, v2;
    cin >> d >> t >> v1 >> v2;
    int ret = 0;
    while (d > 0) {
        if (t > 0) {
            d += v2;
            t--;
        }
        d -= v1;
        ret++;
    }
    cout << ret << endl;

    return 0;
}