#include <iostream>
using namespace std;
bool solve(int p) {
    cout << "Q " << p << endl;
    bool val;
    cin >> val;
    return val;
}
int main() {
    int left = 0, right = 1e5;
    while (left < right) {
        int mid = (left + right + 1) >> 1;
        if (solve(mid)) left = mid;
        else right = mid - 1;
    }
    int cnt = 0, ret = 0;
    for (int i = 0; cnt < left; i += 5) {
        int val = i;
        while (val > 1 && val % 5 == 0) {
            cnt++;
            val /= 5;
        }
        ret = i;
    }
    cout << "A " << ret << endl;
    return 0;
}