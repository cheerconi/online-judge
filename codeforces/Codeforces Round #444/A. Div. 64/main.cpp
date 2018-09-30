#include <iostream>
#include <string>
using namespace std;


int main() {
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') flag = true;
        if (s[i] == '0' && flag) cnt++;
    }
    if (cnt >= 6) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}