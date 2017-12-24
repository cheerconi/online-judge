#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    char op;
    string s;
    int ret = 0;
    set<char> table;
    for (int i = 0; i < 26; i++) {
        table.insert(i+'a');
    }
    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == '!') {
            cin >> s;
            if (table.size() == 1) ret++;
            set<char> tmp;
            for (char c : s) {
                if (table.find(c) != table.end()) tmp.insert(c);
            }
            swap(tmp, table);
        }
        else if (op == '.') {
            cin >> s;
            for (char c : s) {
                auto it = table.find(c);
                if (it != table.end()) table.erase(it);
            }
        }
        else {
            if (table.size() == 1) ret++;
            cin >> op;
            auto it = table.find(op);
            if (it != table.end()) table.erase(it);
        }
    }
    cout << max(ret-1, 0) << endl;
    return 0;
}