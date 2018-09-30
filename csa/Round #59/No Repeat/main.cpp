#include <iostream>
#include <string>
#include <set>
using namespace std;
int cnt[26];
int main() {
    int n;
    string s;
    cin >> n >> s;
    for (char c : s) {
        cnt[c-'a']++;
    }
    set<char> table;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 1) {
            table.insert('a'+i);
        }
    }
    if (table.size() == 0) {
        cout << -1 << endl;
    }
    else {
        for (char c : s) {
            if (table.find(c) != table.end()) {
                cout << c << endl;
                return 0;
            }
        }
    }
    return 0;
}