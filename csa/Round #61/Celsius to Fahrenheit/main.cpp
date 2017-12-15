#include <iostream>
using namespace std;
int main() {
    int c;
    cin >> c;
    double tmp = c + 40;
    tmp = 1.8 * tmp - 40;
    int ret = tmp;
    cout << ret << endl;
    return 0;
}