#include <iostream>
using namespace std;

int main() {
    freopen("test.txt", "r", stdin);
    int c, v0, v1, a, L;
    cin >> c >> v0 >> v1 >> a >> L;
    int cnt = 0;
    while (true) {
        if (v0 > v1) v0 = v1;
        c = c - v0;
        cnt++;
        if (c <= 0) break;
        c += L;
        v0 += a;
    }
    cout << cnt << endl;


    return 0;
}