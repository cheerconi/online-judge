#include <iostream>
using namespace std;
int main() {
    int mod = 10;
    int a = 0, b = 1;
    for (int i = 0; i < 100; i++) {
        int c = (a+b) % mod;
        a = b;
        b = c;
        cout << b << endl;
    }
    return 0;
}