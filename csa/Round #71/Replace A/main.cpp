#include <iostream>
#include <string>
using namespace std;
int main() {
    string s; cin >> s;
    string ret;
    for (char c : s) {
        if (c == 'B') ret.push_back(c);
        else {
            if (ret.empty() || ret.back() == 'B') ret.push_back(c);
        }
    }
    cout << ret << endl;
    return 0;
}