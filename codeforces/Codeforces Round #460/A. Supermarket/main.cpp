#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, m, a, b;
    cin >> n >> m;
    double cheap = 1e9;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cheap = min(cheap, (double)a/b);
    }
    printf("%.8f\n", cheap*m);

    return 0;
}