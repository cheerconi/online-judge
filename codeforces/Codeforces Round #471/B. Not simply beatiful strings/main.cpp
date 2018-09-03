#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<char, int> table;
bool solve() {
    if (table.size() > 4) return false;
    if (table.size() <= 1) return false;
    if (table.size() == 4) return true;
    if (table.size() == 2) {
        for (auto it = table.begin(); it != table.end(); it++) {
            if (it->second == 1) return false;
        }
        return true;
    }
    bool flag = false;
    for (auto it = table.begin(); it != table.end(); it++) {
        if (it->second > 1) flag = true;
    }
    return flag;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    for (char c : s) {
        table[c]++;
    }
    if (solve()) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}