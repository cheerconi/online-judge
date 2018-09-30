#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long LL;
int main() {
    LL n; cin >> n;
    string s = to_string(n);
    LL ret = (s.size()-1) * 9;
    LL cur = 0;
    n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;
        ret = max(ret, cur+s[i]-'0'-1 + (n-i-1)*9);
        cur += s[i] - '0';
    }
    ret = max(ret, cur);
    cout << ret << endl;


    return 0;
}