#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;
int main() {
//    freopen("test.txt", "r", stdin);
    int k;
    string s;
    scanf("%d", &k);
    cin >> s;
    LL cnt = 0;
    for (char c : s) {
        cnt += c - '0';
    }
    if (cnt >= k) {
        cout << 0 << endl;
        return 0;
    }
    sort(s.begin(), s.end());
    int ret = 0;
    for (char c : s) {
        cnt += 9 - (c - '0');
        ret++;
        if (cnt >= k) break;
    }
    cout << ret << endl;

    return 0;
}