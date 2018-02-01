#include <iostream>
using namespace std;
int solve (int n) {
    int ret = 0;
    while (n) {
        ret += n % 10;
        n /= 10;
        if (ret > 10) return ret;
    }
    return ret;
}
int main() {
    int k; cin >> k;
    int i = 1;
    for (; k > 0; i++) {
        if (solve(i) == 10) {
            k--;
        }
    }
    cout << i-1 << endl;
    return 0;
}