#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    string b = s;
    reverse(b.begin(), b.end());
    cout << s+b << endl;

    return 0;
}