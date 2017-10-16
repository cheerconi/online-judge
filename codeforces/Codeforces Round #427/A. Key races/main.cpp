#include <iostream>
using namespace std;

int main() {
//    freopen("test.txt", "r", stdin);
    int s, v1, v2, t1, t2;
    scanf("%d%d%d%d%d", &s, &v1, &v2, &t1, &t2);
    int a = s*v1 + 2*t1;
    int b = s*v2 + 2*t2;
    if (a < b) cout << "First" << endl;
    else if (a > b) cout << "Second" << endl;
    else cout << "Friendship" << endl;
    return 0;
}