#include <iostream>
#include <string>
using namespace std;
bool check (int hh, int mm) {
    string s = to_string(hh) + to_string(mm);
    for (char c : s) {
        if (c == '7') return true;
    }
    return false;
}
int main() {
//    freopen("test.txt", "r", stdin);
    int x, hh, mm;
    cin >> x >> hh >> mm;
    int ret = 0;
    while (true) {
        if (check(hh, mm)) break;
        ret++;
        mm -= x;
        if (mm < 0) {
            mm += 60;
            hh--;
        }
        if (hh < 0) {
            hh = 23;
        }
    }
    cout << ret << endl;
    return 0;
}