#include <iostream>
#include <set>
using namespace std;
set<char> table{'a', 'e', 'i', 'o', 'u'};
int main() {
    string s, t;
    cin >> s >> t;
    if (s.size() != t.size()) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < s.size(); i++) {
        bool x = (table.find(s[i]) == table.end());
        bool y = (table.find(t[i]) == table.end());
        if (x != y) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}