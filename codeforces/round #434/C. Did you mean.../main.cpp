#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
bool check(char c) {
    if (c=='a' || c=='e' || c=='i' || c=='o'|| c=='u') return true;
    return false;
}

int main() {
//    freopen("test.txt", "r", stdin);
    string s;
    cin >> s;
    string ret;
    int i = 0;
    int cnt = 0;
    unordered_set<char> table;
    while (i < s.size()) {
        if (check(s[i])) {
            ret.push_back(s[i++]);
            table.clear();
            cnt = 0;
            continue;
        }
        cnt++;
        table.insert(s[i]);
        if(cnt >= 3 && table.size() >= 2) {
            ret.push_back(' ');
            cnt = 1;
            table.clear();
            table.insert(s[i]);
        }
        ret.push_back(s[i++]);
    }
    cout << ret << endl;
    return 0;
}