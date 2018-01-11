#include <iostream>
#include <algorithm>
using namespace std;

bool solve (int a, int b) {
    cout << "Q " << a << ' ' << b << endl;
    bool val;
    cin >> val;
    return val;
}
int main() {
    int n;
    cin >> n;
    int tot = min(10000, n*(n-1)/2);
    int a = 1, b = 2;
    while (tot > n-1 && b < n) {
        while (true) {
            if (solve(a, b)) break;
            tot--;
        }
        a = b;
        b++;
    }
    cout << "A" << endl;

}