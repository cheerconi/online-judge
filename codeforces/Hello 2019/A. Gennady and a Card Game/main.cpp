#include <iostream>
using namespace std;
int main() {
    string my, other;
    cin >> my;
    for (int i = 0; i < 5; i++) {
        cin >> other;
        if (my[0] == other[0] || my[1] == other[1]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}