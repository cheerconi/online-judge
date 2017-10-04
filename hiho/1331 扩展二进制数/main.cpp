#include <iostream>
using namespace std;

int find(int n) {
    int i = 30;
    while (((1<<i)&n) == 0) i--;
    return i;
}
int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int ret = 1;
    int i = find(n);
    int pre = 0;
    while (i >= 0) {
        if (((1<<i)&n) == 0) {
            ret = ret + pre;
        }
        else {
            pre = ret + pre;
        }
        i--;
    }
    cout << ret << endl;

    return 0;
}