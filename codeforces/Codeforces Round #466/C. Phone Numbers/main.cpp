#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool used[26];
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, t;
    cin >> n >> t;
    string s; cin >> s;
    char mi = 'z';
    for (char c : s) {
        used[c-'a'] = true;
        mi = min(mi, c);

    }
    if (t > n) {
        s += string(t-n, mi);
        cout << s << endl;
        return 0;
    }
    for (int i = t-1; i >= 0; i--) {
        bool done = false;
        int j = s[i]-'a' + 1;
        for (; j < 26; j++) {
            if (used[j]) {
                s[i] = j+'a';
                for (int k = i+1; k < t; k++) {
                    s[k] = mi;
                }
                done = true;
                break;
            }
        }
        if (done) break;
    }
    cout << s.substr(0, t) << endl;



    return 0;
}