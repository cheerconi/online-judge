#include <iostream>
#include <string>
using namespace std;
bool check (char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    if (isdigit(c) && (c-'0') % 2 == 1) return true;
    return false;
}
int main() {
    string s;
    cin >> s;
    int cnt = 0;
    for (char c : s) {
        if (check(c)) cnt++;
    }
    cout << cnt << endl;

    return 0;
}