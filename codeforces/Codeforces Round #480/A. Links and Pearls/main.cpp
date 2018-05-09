#include <iostream>
#include <string>
using namespace std;
int main() {
    string s; cin >> s;
    int links = 0, pearls = 0;
    for (char c : s) {
        if (c == '-') links++;
        else pearls++;
    }
    if (pearls == 0 || links % pearls == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}