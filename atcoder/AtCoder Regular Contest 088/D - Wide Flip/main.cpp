#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> s;
    int n = s.size();
    int ret = n;
    for (int i = 0;  i+1 < n; i++) {
        if (s[i] != s[i+1]) {
            ret = min(ret, max(i+1, n-i-1));
        }
    }
    cout << ret << endl;

}