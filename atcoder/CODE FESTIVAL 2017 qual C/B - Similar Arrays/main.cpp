#include <iostream>
using namespace std;
int main() {
    int n, val;
    cin >> n;
    int a = 1, b = 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        a *= 3;
        if (val % 2 == 0) b *= 2;
    }
    cout << a-b << endl;
    return 0;
}