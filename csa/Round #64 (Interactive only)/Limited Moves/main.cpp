#include <iostream>
using namespace std;
int n;
bool solve () {
    int p = 1, cur = n;
    while (cur % 2 == 0) {
        p = p * 2;
        cur /= 2;
    }
    cout << p << endl;
    n -= p;
    if (n == 0) return true;
    int val;
    cin >> val;
    n -= val;
    return false;
}
int main() {
    cin >> n;
    for (int i = 0; i < 500 && n > 0; i++) {
        if (solve()) break;
    }
    return 0;
}