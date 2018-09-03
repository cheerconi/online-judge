#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    n--;
    int ret = min(a*n, b*n);
    n--;
    if (n > 0) ret = min(ret, min(a, b) + n*c);
    cout << ret << endl;

    return 0;
}