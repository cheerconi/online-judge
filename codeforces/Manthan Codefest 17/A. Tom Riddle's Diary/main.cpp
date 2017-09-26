#include <iostream>
#include <string>
#include <set>
using namespace std;


int main() {
//    freopen("test.txt", "r", stdin);
    set<string> s;
    int n;
    cin >> n;
    string tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (s.find(tmp) != s.end()) cout << "YES" << endl;
        else {
            cout << "NO" << endl;
            s.insert(tmp);
        }
    }
    return 0;
}