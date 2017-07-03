#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int c = min(a, b);
    int ret = 1;
    while (c > 1) {
        ret = ret * c;
        c--;
    }
    cout << ret << endl;
}