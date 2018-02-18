#include <iostream>
#include <set>
using namespace std;
int main() {
    int n; cin >> n;
    string s; cin >> s;
    set<char> vowel{'a', 'e', 'i', 'o', 'u', 'y'};
    string ret;
    for (int i = 0; i < n; i++) {
        if (ret.size()!=0 && vowel.find(s[i])!=vowel.end() && vowel.find(ret.back())!=vowel.end()) {
            continue;
        }
        ret.push_back(s[i]);
    }
    cout << ret << endl;
    return 0;
}