#include <iostream>
using namespace std;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < 100000; i++) {
        if (b > a) {
            if (a+1 != b) a++;
            else a--;
        }
        else {
            if (a-1 != b) a--;
            else a++;
        }
        if (a <= 0 || a > n) {
            cout << "Borys" << endl;
            return 0;
        }
        if (a > b) {
            if (b+1 != a) b++;
            else b--;
        }
        else {
            if (b-1 != a) b--;
            else b++;
        }
        if (b <= 0 || b > n) {
            cout << "Alice" << endl;
            return 0;
        }

    }
    cout << "Draw" << endl;
    return 0;
}