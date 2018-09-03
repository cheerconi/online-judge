#include <iostream>
#include <string>
using namespace std;
int main() {
    int n; cin >> n;
    string s;
    for (int i = 1; i <= n; i++) {
        s.append(to_string(i));
        if (s.size() >= n) break;
    }
    cout << s[n-1] << endl;
    return 0;
}