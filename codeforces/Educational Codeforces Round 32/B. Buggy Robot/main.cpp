#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n >> s;
    int x = 0, y = 0;
    for (char c : s) {
        if (c == 'L') x--;
        if (c == 'R') x++;
        if (c == 'U') y++;
        if (c == 'D') y--;
    }
    cout << n - abs(x) - abs(y) << endl;
    return 0;
}