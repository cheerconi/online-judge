#include <iostream>
using namespace std;
typedef long long LL;

int main() {
//    freopen("test.txt", "r", stdin);
    int a1,a2,b1,b2,c1,c2;
    scanf("%d%d%d%d%d%d", &a1, &a2, &b1, &b2, &c1, &c2);
    LL x1 = a1 - b1;
    LL x2 = a2 - b2;
    LL x = x1*x1 + x2*x2;
    LL y1 = b1 - c1;
    LL y2 = b2 - c2;
    LL y = y1*y1 + y2*y2;
    if (x != y || x1*y2==x2*y1) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}