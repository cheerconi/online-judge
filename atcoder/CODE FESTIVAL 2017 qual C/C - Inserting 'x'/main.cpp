#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solve (string & s) {
    string s1;
    for (char c : s) {
        if (c != 'x') s1.push_back(c);
    }
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    if (s1 != s2) return -1;
    int n1 = s1.size();
    if (n1 == 0) return 0;
    int tmpj = n1 / 2;
    int tmpi = tmpj;
    if (n1 % 2 == 0) tmpi--;
    int j = 0, i = 0;
    while (tmpi) {
        if (s[i] != 'x') tmpi--;
        i++;
    }
    int n = s.size();
    while (i < n && s[i] == 'x') i++;
    while (tmpj) {
        if (s[j] != 'x') tmpj--;
        j++;
    }
    while (j < n && s[j] == 'x') j++;
    int cnt = 0;
    while (i >= 0 && j < n) {
        if (s[i] == s[j]) {
            i--;
            j++;
        }
        else {
            while (i >= 0 && s[i]=='x') {
                i--;
                cnt++;
            }
            while (j < n && s[j] =='x') {
                j++;
                cnt++;
            }
        }
    }
    while (j < n && s[j] =='x') {
        j++;
        cnt++;
    }
    while (i >= 0 && s[i]=='x') {
        i--;
        cnt++;
    }
    return cnt;
}

int main() {
//    freopen("test.txt", "r", stdin);
    string s;
    cin >> s;
    cout << solve(s) << endl;

    return 0;
}