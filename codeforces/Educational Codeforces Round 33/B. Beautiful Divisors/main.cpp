#include <iostream>
using namespace std;
int main() {
    int n;
    int ret = 1;
    cin >> n;
    int i = 1, k = 1;
    while (i <= n) {
        if (n % i == 0) ret = i;
        i = i << 2;
        i += (1<<k);
        k++;
    }
    cout << ret << endl;
    return 0;
}