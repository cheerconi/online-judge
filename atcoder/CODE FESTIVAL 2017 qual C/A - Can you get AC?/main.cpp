#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool flag = false;
    for (int i = 0; i+1 < s.size(); i++) {
        if (s[i] == 'A' && s[i+1]== 'C') {
            flag = true;
            break;
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}