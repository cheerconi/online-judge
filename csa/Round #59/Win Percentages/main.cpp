#include <iostream>
#include <algorithm>
typedef long long LL;
using namespace std;
int main() {
//    freopen("test.txt", "r", stdin);
    int g1, p1, g2, p2;
    cin >> g1 >> p1 >> g2 >> p2;
    int a = 0, b = g2;
    while (true) {
        int tmp = 100*a / g1;
        if (tmp == p1) break;
        a++;
    }
    while (true) {
        int tmp = 100*b / g2;
        if (tmp == p2) break;
        b--;
    }
    cout << min(b-a, g2-g1) << endl;

    return 0;
}