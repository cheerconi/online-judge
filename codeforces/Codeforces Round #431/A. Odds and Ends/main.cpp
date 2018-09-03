#include <iostream>
using namespace std;

int main() {
//    freopen("test.txt", "r", stdin);
    int tmp, n;
    scanf("%d", &n);
    if (n % 2 == 0) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if (i == 0 || i == n-1) {
            if (tmp%2 == 0) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}