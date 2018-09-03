#include <iostream>
using namespace std;

void solve (int n) {
    cout << n + n / 2 << endl;
    for (int i = 2; i <= n; i += 2) {
        printf("%d ", i);
    }
    for (int i = 1; i <= n; i += 2) {
        printf("%d ", i);
    }
    for (int i = 2; i <= n; i += 2) {
        printf("%d", i);
        if (i == n || i == n-1) printf("\n");
        else printf(" ");
    }

}

int main() {
    int n;
    cin >> n;
    solve(n);
    return 0;
}