#include <iostream>
#include <string>
#include <assert.h>
using namespace std;
string s;
int solve(int & i) {
    int ret;
    if (s[i] == '(') {
        i++;
        ret = solve(i);
        i++;
        if (i == s.size()) return ret;
        if (s[i] == ')') return ret;
        assert(s[i] == ',');
        i++;
        return solve(i);
    }
    for (int j = i; j < s.size(); j++) {
        if (s[j] == ',') {
            i = j+1;
            return solve(i);
        }
        if (s[j] == ')') {
            ret = stoi(s.substr(i, j-i));
            i = j;
            return ret;
        }
    }
    return stoi(s.substr(i));
}

int main() {
//    freopen("test.txt", "r", stdin);
    cin >> s;
    s = "(" + s + ")";
    int i = 0;
    cout << solve(i) << endl;

}
