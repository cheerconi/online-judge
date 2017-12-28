#include <iostream>
#include <string>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    string ret(1, a[0]);
    for (int i = 1; i < a.size(); i++) {
        if (a[i] < b[0]) ret.push_back(a[i]);
        else break;
    }
    ret.push_back(b[0]);
    cout << ret << endl;
    return 0;
}