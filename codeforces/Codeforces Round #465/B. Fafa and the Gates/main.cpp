#include <iostream>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    int x = 0, y = 0, delta = 0;
    for (char c : s) {
        if (c == 'R') x++;
        else y++;
        if (x == y) continue;
        if (x > y) {
            if (delta < 0) cnt++;
            delta = x - y;
        }
        else {
            if (delta > 0) cnt++;
            delta = x - y;
        }
    }
    cout << cnt << endl;
    return 0;
}