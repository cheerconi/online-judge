#include <iostream>
using namespace std;
typedef long long LL;
int main() {
    LL a, b;
    cin >> a >> b;
    int cnt = 0;
    while (a > 0 && a <= b) {
        cnt++;
        a <<= 1;
    }
    cout << cnt << endl;
    return 0;
}