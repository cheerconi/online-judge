#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;
int main() {
    int k, p;
    cin >> k >> p;
    LL base = 1, ret = 0;
    while (k) {
        for (LL i = base; i < base*10; i++) {
            LL tmp = i * base * 10;
            string s = to_string(i);
            reverse(s.begin(), s.end());
            tmp += stoi(s);
            ret = (tmp + ret) % p;
            k--;
            if (k == 0) break;
        }
        base = base * 10;

    }
    cout << ret << endl;
    return 0;
}