#include <iostream>
#include <string>
using namespace std;

int main() {
//    freopen("test.txt", "r", stdin);
    string x, y;
    cin >> x >> y;
    string ret;
    for (int i = 0; i < x.size(); i++) {
        if (y[i] > x[i]) {
            cout << -1 << endl;
            return 0;
        }
        ret.push_back(y[i]);
    }
    cout << ret << endl;
    return 0;
}