#include <iostream>
using namespace std;
int n, a, b;
bool check (int x) {
    if (x == 0) return true;
    if (a < x || b < x) return false;
    int tmp = n - a / x;
    tmp -= b / x;
    if (tmp > 0) return false;
    return true;
}
int main() {
    cin >> n >> a >> b;
    int left = 0, right = 200;
    while (left < right) {
        int mid  = (left+right+1) >> 1;
        if (check(mid)) left = mid;
        else right = mid - 1;
    }
    cout << left << endl;
    return 0;
}