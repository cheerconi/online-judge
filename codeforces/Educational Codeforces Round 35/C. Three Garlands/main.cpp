#include <iostream>
#include <algorithm>
using namespace std;
int a[3];

bool solve() {
    if (a[0] == 1) return true;
    if (a[0] == a[1] && a[0] == 2) return true;
    if (a[0] == 2 && a[1] == a[2] && a[1] == 4) return true;
    if (a[0] == a[2] && a[0] == 3) return true;
    return false;
}
int main() {

    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    if (solve()) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}