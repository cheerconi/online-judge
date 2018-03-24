#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 123;
int main() {
    int n; cin >> n;
    int ret = n;
    string s; cin >> s;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0 && s.substr(0, i/2) == s.substr(i/2, i/2)) {
            ret = min(ret, n-i/2+1);
        }
    }
    cout << ret << endl;
    return 0;
}