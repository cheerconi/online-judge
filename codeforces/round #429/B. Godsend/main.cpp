#include <iostream>
using namespace std;
int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int sum = 0, tmp;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        sum = (sum + tmp) % 2;
        if (sum == 1) flag = true;
    }
    if (sum == 1 || flag) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}