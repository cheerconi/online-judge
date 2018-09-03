#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool solve() {
    string s1, s2;
    cin >> s1;
    s2 = s1;
    reverse(s2.begin(), s2.end());
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            s1[i] = s2[i];
            string s3 = s1;
            reverse(s3.begin(), s3.end());
            if (s1 == s3) return true;
            else return false;
        }

    }
    if (s1.size()%2 == 0) return false;
    return true;
}

int main() {
//    freopen("test.txt", "r", stdin);
    if (solve()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}