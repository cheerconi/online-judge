#include <iostream>
#include <string>
using namespace std;

int main() {
    string pw;
    cin >> pw;
    int n;
    cin >> n;
    bool first = false, second = false;
    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        if (tmp.back() == pw[0]) first = true;
        if (tmp[0] == pw[1]) second = true;
        if (tmp == pw) {
            first = true;
            second = true;
            break;
        }
    }
    if (first && second) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0;
}