#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1e6 + 200;
const int mod = 1e9 + 7;
int coeff[MAXN], factor[MAXN], inv[MAXN], last[MAXN];

int power(int base, int p) {
    int ret = 1;
    while (p) {
        if (p&1) ret = 1LL * ret * base % mod;
        base = 1LL * base * base % mod;
        p >>= 1;
    }
    return ret;
}
void make_table() {
    coeff[1] = 1;
    for (int i = 2; i < MAXN; i++) coeff[i] = 2*coeff[i-1] % mod;

    factor[0] = 1;
    for (int i = 1; i < MAXN; i++) factor[i] = 1LL * factor[i-1] * i % mod;

    inv[MAXN-1] = power(factor[MAXN-1], mod-2);
    for (int i = MAXN-2; i >= 0; i--) inv[i] = 1LL * inv[i+1] * (i+1) % mod;
    for (int i = 2; i < MAXN; i++) {
        if (last[i]) continue;
        for (int j = i+i; j < MAXN; j += i) {
            if (last[j] == 0) last[j] = i;
        }
    }

}
int x, y;
int solve(vector<int> &nums) {
    int ret = 1;
    for (int num : nums) {
        ret = 1LL * ret * factor[num+y-1] % mod * inv[y-1] % mod * inv[num] % mod;
    }
    ret = 1LL * ret * coeff[y] % mod;
    return ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    make_table();
    int q;
    cin >> q;
    while (q--) {
        scanf("%d%d", &x, &y);
        vector<int> nums;
        while (last[x]) {
            int p = last[x];
            nums.push_back(0);
            while (x % p == 0) {
                nums.back()++;
                x /= p;
            }
        }
        if (x != 1) nums.push_back(1);
        printf("%d\n", solve(nums));
    }
    return 0;
}