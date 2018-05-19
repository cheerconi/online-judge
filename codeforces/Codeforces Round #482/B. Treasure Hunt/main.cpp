#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int solve(string & s, int q) {
    map<char, int> table;
    for (char c : s) table[c]++;
    int n = s.size();
    int m = 0;
    for (auto it = table.begin(); it != table.end(); it++) {
        m = max(m, it->second);
    }
    if (q == 1 && m == n) return max(n-1, 1);
    if (n-m <= q) return n;
    return m+q;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q; cin >> q;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int a1 = solve(s1, q);
    int a2 = solve(s2, q);
    int a3 = solve(s3, q);
    if (a1 > a2 && a1 > a3) {
        cout << "Kuro" << endl;
    }
    else if (a2 > a1 && a2 > a3) {
        cout << "Shiro" << endl;
    }
    else if (a3 > a1 && a3 > a2) {
        cout << "Katie" << endl;
    }
    else cout << "Draw" << endl;

    return 0;
}