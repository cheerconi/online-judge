#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
int main() {
    int n;
    string ret;
    cin >> n >> ret;
    set<int> cur;
    cur.insert(0);
    string s;
    for (int i = 1; i < n; i++) {
        cin >> s;
        set<int> pos;
        char m = 'z' + 1;
        for (int x : cur) {
            if (m > s[x]) {
                pos.clear();
                pos.insert(x);
                m = s[x];
            }
            else if (m == s[x]) {
                pos.insert(x);
            }
            if (m > s[x+1]) {
                pos.clear();
                pos.insert(x+1);
                m = s[x+1];
            }
            else if (m == s[x+1]) {
                pos.insert(x+1);
            }
        }
        ret.push_back(m);
        swap(pos, cur);
    }
    cout << ret << endl;

    return 0;
}