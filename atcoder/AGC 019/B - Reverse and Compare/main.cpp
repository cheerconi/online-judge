#include <iostream>
#include <string>
typedef long long LL;
using namespace std;
int cnt[26];
int main () {
//    freopen("test.txt", "r", stdin);
    string s;
    cin >> s;
    LL ret = 1;
    for (char c : s) {
        for (int i = 0; i < 26; i++) {
            if (i == c-'a') continue;
            ret += cnt[i];
        }
        cnt[c-'a']++;
    }
    cout << ret << endl;

}