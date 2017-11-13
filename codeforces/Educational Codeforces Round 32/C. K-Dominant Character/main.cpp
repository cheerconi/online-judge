#include <iostream>
#include <string>
#include <memory.h>
#include <set>
using namespace std;
string s;
int cnt[26];
bool check(int num) {
    if (num == 0) return false;
    if (num == s.size()) return true;
    memset(cnt, 0, sizeof(cnt));
    set<char> table;
    for (int i = 0; i < num; i++) {
        table.insert(s[i]);
        cnt[s[i]-'a']++;
    }
    for (int i = num; i < s.size(); i++) {
        cnt[s[i-num]-'a']--;
        cnt[s[i]-'a']++;
        if (cnt[s[i-num]-'a'] == 0) {
            table.erase(s[i-num]);
        }
        if (table.empty()) break;
    }
    return !table.empty();
}

int main() {
//    freopen("test.txt", "r", stdin);
    cin >> s;
    int left = 0, right = s.size();
    while (left < right) {
        int mid = (left+right + 1) >> 1;
        if (check(mid)) {
            right = mid - 1;
        }
        else {
            left = mid;
        }
    }
    cout << left+1 << endl;

    return 0;
}