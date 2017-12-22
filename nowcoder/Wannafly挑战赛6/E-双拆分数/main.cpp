#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n <= 3) {
        cout << -1 << endl;
        return 0;
    }
    if (n % 2 == 1) {
        cout << 164;
        cout << string(n-3, '0') << endl;
        return 0;
    }
    string s;
    int m = n / 4 * 4;
    string s1 = string(m/2, '1');
    string s2 = string(m/2, '4');
    s = s1 + s2;
    if (n % 4 == 2) s += string(2, '0');
    cout << s << endl;
}