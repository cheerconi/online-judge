#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a = 0, b = 0, c = 0;
    if (n % 10 != 0) {
        a = 1;
    }
    b = a;
    if (n % 5 != 0) {
        b++;
    }
    c = b;
    if (n*3 % 10 != 0) c++;
    cout << a << ' ' << b << ' ' << c << endl;
    return 0;
}