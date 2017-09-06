#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool check(int i, int j) {
    if (i >= j) return false;
    if (gcd(i, j) != 1) return false;
    return true;

}

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = n/2; i >= 1; i--) {
        if (check(i, n-i)) {
            cout << i << ' ' << n-i << endl;
            return 0;
        }
    }
    return 0;
}