#include <iostream>
using namespace std;

int main() {
    int t = 0, n, m;
    cin >> n >> m;
    t = (n-m)*100 + m*1900;
    while (m > 0) {
        t *= 2;
        m--;
    }
    cout << t << endl;
    return 0;
}