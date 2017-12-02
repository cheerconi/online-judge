#include <iostream>
#include <string>
using namespace std;
int main() {
    int n, m, a, b;
    char c1, c2;
    string s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c1 >> c2;
        for (int i = a-1; i < b; i++) {
            if (s[i] == c1) s[i] = c2;
        }
    }
    cout << s << endl;

    return 0;
}