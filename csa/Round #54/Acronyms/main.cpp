#include <iostream>
#include <string>
using namespace std;
const int MAXN = 1e5 + 10;
int acronym[26];
int state[MAXN][27];
bool check (int k) {
    acronym[state[k][26]]--;
    bool flag = true;
    for (int i = 0; i < 26; i++) {
        if (state[k][i] > acronym[i]) {
            flag = false;
            break;
        }
    }
    acronym[state[k][26]]++;
    return flag;
}
int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        acronym[s[0]-'a']++;
        state[i][26] = s[0]-'a';
        for (char c : s) {
            state[i][c-'a']++;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (check(i)) cnt++;
    }
    cout << cnt << endl;

    return 0;
}