#include <iostream>
using namespace std;

int ret[123];

int main() {
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        for (int j = 1; j <= 100; j++) {
            if (abs(val-j) <= 1) continue;
            if (val > j) ret[j] += val - j - 1;
            else ret[j] += j-1 - val;
        }
    }
    int idx = 1;
    for (int i = 2; i <= 100; i++) {
        if (ret[i] < ret[idx]) {
            idx = i;
        }
    }
    cout << idx << ' ' << ret[idx] << endl;

    return 0;
}