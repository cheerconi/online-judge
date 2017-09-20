#include <iostream>
using namespace std;
const int MAXN = 1e5 + 10;
int nums[MAXN];

bool solve(int n, int x) {
    if (n == 1) {
        nums[0] = x;
        return true;
    }
    if(n == 2 && x == 0) return false;
    if (n == 2) {
        nums[1] = x;
        return true;
    }
    int now = 0;
    for (int i = 0; i < n-3; i++) {
        nums[i] = i;
        now = now ^ i;
    }
    nums[n-3] = 1 << 17;
    nums[n-2] = 1 << 18;
    nums[n-1] = nums[n-3]^nums[n-2]^now^x;
    return true;
}
int main() {
    int n, x;
    cin >> n >> x;
    if (solve(n, x)) {
        printf("YES\n");
        for (int i = 0; i < n; i++) {
            printf("%d", nums[i]);
            if (i == n-1) printf("\n");
            else printf(" ");
        }
    }
    else printf("NO\n");
    return 0;
}
