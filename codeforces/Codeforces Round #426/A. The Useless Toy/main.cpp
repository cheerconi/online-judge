#include <iostream>
using namespace std;

int pos[256];

int main() {
//    freopen("test.txt", "r", stdin);
    pos['v'] = 0;
    pos['<'] = 1;
    pos['^'] = 2;
    pos['>'] = 3;
    char a, b, tmp;
    scanf("%c%c%c", &a, &tmp, &b);
    int d;
    scanf("%d", &d);
    int dis = pos[b] - pos[a];
    dis %= 4;
    if (dis < 0) dis += 4;
    d %= 4;
    if ((d == 1 || d == 3) && d == dis) {
        cout << "cw" << endl;
    }
    else if ((d == 1 || d == 3) && d == 4 - dis) {
        cout << "ccw" << endl;
    }
    else cout << "undefined" << endl;


    return 0;
}