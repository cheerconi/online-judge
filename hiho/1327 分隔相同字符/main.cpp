#include <iostream>
#include <string>
using namespace std;
int cnt[26];

bool check (int i, int n) {
    if (cnt[i] == 0) return false;
    if (cnt[i]-1 > (n-1)/2) return false;
    for (int j = 0; j < 26; j++) {
        if (i == j) continue;
        if (cnt[j] > n/2) return false;
    }
    return true;

}

int main() {
//    freopen("test.txt", "r", stdin);
    int pre = -1;
    string s;
    cin >> s;
    for (char c : s) cnt[c-'a']++;

    for (int i = 0; i < s.size(); i++) {
        bool flag = false;
        for (int j = 0; j < 26; j++) {
            if (pre == j) continue;
            flag = check(j, s.size()-i);
            if (flag) {
                cnt[j]--;
                printf("%c", 'a'+j);
                pre = j;
                break;
            }
        }
        if (!flag) {
            cout << "INVALID" << endl;
            return 0;
        }

    }
    cout << endl;
    return 0;



}