#include <iostream>
using namespace std;
typedef long long LL;

bool check1(int n) {
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return true;
    }
    return false;
}
int power(int n, LL i) {
    int ret = 1;
    int mod = n;
    while (n) {
        if (n&1) ret = (ret*i) % mod;
        i = (i*i) % mod;
        n >>= 1;
    }
    return ret;
}
bool check2(int n) {
    for (int i = 2; i < n; i++) {
        if (power(n, i) != i) return false;
    }
    return true;

}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        if (n == 0) break;
        if (check1(n) && check2(n)) printf("The number %d is a Carmichael number.\n", n);
        else printf("%d is normal.\n", n);
    }
    return 0;
}