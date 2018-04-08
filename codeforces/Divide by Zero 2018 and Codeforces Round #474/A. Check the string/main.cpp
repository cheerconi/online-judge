#include <iostream>
#include <string>
using namespace std;
int main() {
    string s; cin >> s;
    int i = 0, a = 0, b = 0, c = 0;
    while (i < s.size() && s[i] == 'a') {
        a++;
        i++;
    }
    while (i < s.size() && s[i] == 'b') {
        b++;
        i++;
    }
    while (i < s.size() && s[i] == 'c') {
        c++;
        i++;
    }
    if (a == 0 || b == 0 || c == 0 || i != s.size()) {
        cout << "NO" << endl;
        return 0;
    }
    if (c == a || c == b) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}