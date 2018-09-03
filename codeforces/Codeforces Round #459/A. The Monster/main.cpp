#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int ret = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ')') continue;
        int mi = 1, ma = 1;
        for (int j = i+1; j < s.size(); j++) {
            if (s[j] == '(') {
                mi++;
                ma++;
            }
            else if (s[j] == ')') {
                mi--;
                ma--;
            }
            else {
                mi--;
                ma++;
            }
            if (ma < 0) break;
            if (mi < 0) {
                mi = 0;
                if (ma % 2 == 1) mi++;
            }
            if (mi <= 0 && 0 <= ma && ma%2 == 0) {
//                cout << s.substr(i, j-i+1) << endl;
                ret++;
            }
        }
    }
    cout << ret << endl;

    return 0;
}