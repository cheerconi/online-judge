#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
int nums[MAXN];

int gcd(int a, int b) {
    if (b > a) return gcd(b, a);
    if (a % b == 0) return b;
    return gcd(a%b, b);
}

bool solve (int n, int k) {
    scanf("%d", &nums[0]);
    if (n == 1) {
        if (nums[0] == k) return true;
        else return false;
    }
    int big = nums[0];
    for (int i = 1; i < n; i++) {
        scanf("%d", &nums[i]);
        if (nums[i] == k) return true;
        big = max(big, nums[i]);
    }
    if (k > big) return false;
    for (int i = 0; i < n; i++) {
        big = gcd(big, nums[i]);
        if (k % big == 0) return true;
    }
    return false;
}
int main() {
//    freopen("test.txt", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    if (solve(n, k)) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;


}