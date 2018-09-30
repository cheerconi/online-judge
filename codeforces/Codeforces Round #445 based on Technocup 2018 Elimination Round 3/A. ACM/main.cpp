#include <iostream>
using namespace std;
int a[6];
int main() {
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (i == j) continue;
            for (int k = 0; k < 6; k++) {
                if (k == i || k == j) continue;
                int tmp = a[i] + a[j] + a[k];
                if (2*tmp == sum) {
                    cout << "YES" << endl;
                    return 0;
                }
            }

        }
    }
    cout << "NO" << endl;
    return 0;
}