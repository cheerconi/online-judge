#include <iostream>
#include <string>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int left, right;
    char c1, c2;
    for (int i = 0; i < m; i++) {
        cin >> left >> right >> c1 >> c2;
        left--; right--;
        for (int j = left; j <= right; j++) {
            if (s[j] == c1) s[j] = c2;
        }
    }
    cout << s << endl;
    return 0;
}