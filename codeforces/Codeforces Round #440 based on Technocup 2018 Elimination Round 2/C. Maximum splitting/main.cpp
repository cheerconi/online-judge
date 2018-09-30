#include <iostream>
using namespace std;
int solve(int num) {
    if (num <= 3) return -1;
    if (num % 4 == 0) return num / 4;
    if (num % 4 == 1) {
        if (num == 5) return -1;
        return (num-9) / 4 + 1;
    }
    if (num % 4 == 2) {
        return (num-6) / 4 + 1;
    }
    if (num % 4 == 3) {
        if (num <= 11) return -1;
        return (num-15) / 4 + 2;
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    int q, num;
    cin >> q;
    while (q--) {
        scanf("%d", &num);
        printf("%d\n", solve(num));
    }
    return 0;
}