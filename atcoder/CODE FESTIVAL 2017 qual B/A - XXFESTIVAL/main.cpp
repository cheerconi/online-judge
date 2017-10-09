#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    cout << s.substr(0, n-8) << endl;
    return 0;
}