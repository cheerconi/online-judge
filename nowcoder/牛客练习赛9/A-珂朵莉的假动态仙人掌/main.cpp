#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ret = n / 3 * 2;
    n = n % 3;
    if (n != 0) ret++;
    cout << ret << endl;
    return 0;
}