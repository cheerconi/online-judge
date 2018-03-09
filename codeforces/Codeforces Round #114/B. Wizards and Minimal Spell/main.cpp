#include <iostream>
#include <string>
using namespace std;

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    bool spell, pre = true;
    string s, tmp;
    while (getline(cin, s)) {
        int i = 0;
        for (; i < s.size(); i++) {
            if (s[i] != ' ') break;
        }
        if (i < s.size() && s[i] == '#') spell = true;
        else spell = false;
        if (spell) {
            if (!pre) cout << '\n';
            cout << s << '\n';

        }
        else {
            tmp.clear();
            for (char c : s) {
                if (c != ' ') tmp.push_back(c);
            }
            cout << tmp;
        }
        pre = spell;
    }
    if (!spell) cout << '\n';
}