#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int table[26];
int sub[26];
int letter[26];

int main() {
//    freopen("test.txt", "r", stdin);
    string s, t;
    cin >> s >> t;
    int any = 0;
    for (char c : s) {
        if (c == '?') any++;
        else table[c-'a']++;
    }
    for (char c : t) {
        sub[c-'a']++;
    }
    int ret = 0;
    while (true) {
        bool flag = true;
        for (int i = 0; i < 26; i++) {
            table[i] = table[i] - sub[i];
            if (table[i] < 0) {
                letter[i] += min(any, -table[i]);
                any += table[i];
                table[i] = 0;
                if (any < 0) {
                    flag = false;
                    break;
                }
            }
        }
        if (!flag) break;
        ret++;
    }
    int k = 0;
    letter[25] += s.size();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?') {
            while (k < 26 && letter[k]==0) k++;
            if (k < 26) {
                s[i] = k+'a';
                letter[k]--;
            }
        }
    }
    cout << s << endl;
    return 0;
}