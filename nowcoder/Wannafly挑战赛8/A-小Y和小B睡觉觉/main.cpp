#include <iostream>
using namespace std;

int main() {
//    freopen("test.txt", "r", stdin);
    string s;
    cin >> s;
    int a, b, c;
    scanf("%d:%d:%d", &a, &b, &c);
    int t; cin >> t;
    int now = c + b*60 + a*3600 + t;
    int d = now / (3600*24);
    cout << d << endl;
    return 0;
}