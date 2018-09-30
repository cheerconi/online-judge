#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) != EOF) {
        cout << a*b*c << endl;
    }
    return 0;
}