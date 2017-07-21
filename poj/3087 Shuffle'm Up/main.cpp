#include <iostream>
#include <string>
#include <set>

using namespace std;

string shuffle(string s1, string s2) {
    int n = s1.size() * 2;
    string ret(n, '0');
    for (int i = 0; i < n; i += 2) ret[i] = s1[i/2];
    for (int i = 1; i < n; i += 2) ret[i] = s2[i/2];
    return ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        set<string> table;
        int n;
        string s1,s2, s12;
        scanf("%d", &n);
        cin >> s1 >> s2 >> s12;
        string tmp;
        int cnt = 1;
        while ((tmp = shuffle(s2, s1)) != s12) {
            if (table.find(tmp) != table.end()) {
                cnt = -1;
                break;
            }
            else {
                table.insert(tmp);
                s1 = tmp.substr(0, n);
                s2 = tmp.substr(n);
            }
            cnt++;
        }
        cout << i << ' ' << cnt << endl;




    }
    return 0;
}