#include <iostream>
#include <string>
#include <vector>
using namespace std;
int state[10];
void solve (char c, int val) {
    if (c == '|') {
        for (int i = 0; i < 10; i++) {
            if (val & (1<<i)) {
                state[i] = 1;
            }
        }
    }
    else if (c == '^') {
        for (int i = 0; i < 10; i++) {
            if (val & (1<<i)) {
                state[i] = -state[i];
            }
        }
    }
    else if (c == '&') {
        for (int i = 0; i < 10; i++) {
            if ((val & (1<<i)) == 0) {
                state[i] = -1;
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    char c;
    int val;
    for (int i = 0; i < 10; i++) state[i] = 2;
    for (int i = 0; i < n; i++) {
        cin >> c >> val;
        solve(c, val);
    }

    val = 0;
    for (int i = 0; i < 10; i++) {
        if (state[i] == -2) {
            val |= (1<<i);
        }
    }
    int mask = (1<<10) -1;
    vector<string> ret;
    if (val != 0) {
        ret.push_back(string("^ "));
        ret.back() += to_string(val);
    }
    val = mask;
    for (int i = 0; i < 10; i++) {
        if (state[i] == -1) {
            val ^= (1<< i);
        }
    }
    if (val == 0) {
        ret.push_back(string("& 1"));
        ret.push_back(string("& 2"));
    }
    else {
        ret.push_back(string("& "));
        ret.back() += to_string(val);
    }
    val = 0;
    for (int i = 0; i < 10; i++) {
        if (state[i] == 1) {
            val |= (1<<i);
        }
    }
    if (val != 0) {
        ret.push_back(string("| "));
        ret.back() += to_string(val);
    }
    cout << ret.size() << endl;
    for (string s : ret) {
        cout << s << endl;
    }
    return 0;
}