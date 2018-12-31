#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int y, b, r;
    cin >> y >> b >> r;
    int x = y;
    x = min(x, b-1);
    x = min(x, r-2);
    cout << x*3 + 3 << endl;
    return 0;
}