#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int a, b;
    if(k == 0) a = 0;
    else {
        a = min(1, n-k);
    }
    if(n%3 == 0) {
        if (k > n/3) b = n - k;
        else b = 2*k;
    }
    else if (n%3 == 1) {
        if (k > (n-1)/3) b = n - k;
        else b = 2*k;
    }
    else {
        if (k > (n-2)/3) b = n - k;
        else b = 2*k;
    }
    cout << a << ' ' << b << endl;
    return 0;
}