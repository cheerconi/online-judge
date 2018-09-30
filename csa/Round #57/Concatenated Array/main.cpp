#include <iostream>
#include <string>
#include <algorithm>
typedef long long LL;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') break;
        a++;
    }
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == '1') break;
        b++;
    }
    LL ret = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') cur = 0;
        else cur++;
        ret = max(ret, cur);
    }

    if (a == n) {
        ret = max(1LL * n * k, ret);
    }
    else if (k > 1) {
        ret = max((LL)a + b, ret);
    }
    cout << ret << endl;

    return 0;
}