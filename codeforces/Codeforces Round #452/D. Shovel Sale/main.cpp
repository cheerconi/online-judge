#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long LL;
LL solve (LL n) {
    if (n <= 4) return (n-1)*n / 2;
    if (n == 9) return 4;
    if (n < 9) return max(0LL, n-4);
    LL m = n + n - 1;
    string s = to_string(m);
    if (count(s.begin(), s.end(), '9') == s.size()) return 1;
    int len = s.size()-1;
    LL ret = 0;
    s = string(len, '9');
    for (int i = 0; i < 9; i++) {
        string tmp = to_string(i) + s;
        LL val = stoll(tmp);
        if (val <= m) {
            LL delta = val - 1  - 2*max(val - n - 1, 0LL);
            ret += delta / 2;
        }
    }
    return ret;

}
int main() {
    LL n;
    cin >> n;
    cout << solve(n) << endl;

    return 0;
}