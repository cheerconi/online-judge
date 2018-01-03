#include <iostream>
#include <string>
using namespace std;
int main() {
    int n, m, val;
    cin >> n >> m;
    string s1, s2;
    for (int i = 0; i < n; i++) {
        cin >> val;
        s1.push_back(val+'0');
    }
    for (int i = 0; i < m; i++) {
        cin >> val;
        s2.push_back(1 - val+'0');
    }
    int cnt = 0;
    for (int i = 0; i+s1.size() <= s2.size(); i++) {
        if (s2.substr(i, s1.size()) == s1) cnt++;
    }
    cout << cnt << endl;

    return 0;
}