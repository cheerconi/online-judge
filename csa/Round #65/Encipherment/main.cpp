#include <iostream>
#include <string>
using namespace std;
int table[26];
int main() {
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < 26; i++) {
        table[i] = t[i]-'a';
    }
    string ret;
    for (char c : s) {
        ret.push_back('a'+table[c-'a']);
    }
    cout << ret << endl;

    return 0;
}