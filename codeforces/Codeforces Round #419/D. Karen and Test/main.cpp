#include <iostream>
const int MOD = 1e9 + 7;
#define _ %MOD

typedef long long LL;
using namespace std;

const int MAXN = 200000 + 10;


LL coef[MAXN>>1];
int nums[MAXN];
LL factor[MAXN>>1];

LL quick_power(int base, int power) {
    LL ret = 1;
    LL cur = base;
    while (power != 0) {
        if (power & 1) {
            ret *= cur;
            ret = ret _;
        }
        cur *= cur;
        cur = cur _;
        power = power >> 1;
    }
    return ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        scanf("%d ", &nums[n]);
    }
    if ((N&1) == 1) {
        LL sign = 1;
        for (int n = 0; n < N-1; n++) {
            nums[n] = (sign * nums[n+1] + (LL)nums[n])_;
            sign = -sign;
        }
        N--;
    }
    N = N >> 1;
    factor[0] = 1;
    factor[1] = 1;
    for(int n = 2; n <= N; n++) {
        factor[n] = (n * factor[n-1])_;
    }
    coef[0] = 1;
    coef[1] = N-1;
    for (int n = 2; n < N; n++) {
        int base = (factor[n] * factor[N-1-n])_;
        coef[n] = (factor[N-1] * quick_power(base, MOD-2))_;
//        cout << base << endl;
//        cout << factor[N-1] << endl;
//        cout << factor[N-1-n] << endl;
//        cout << quick_power(base, MOD-2) << endl;
//        cout << coef[n] << endl;
    }
//    for(int n = 0; n < N; n++) cout << coef[n] << ' ';
//    cout << endl;



    LL sum1 = 0;
    LL sum2 = 0;
    for (int n = 0; n < N; n++) {
        sum1 += coef[n]*nums[n<<1];
        sum2 += coef[n]*nums[(n<<1)|1];
        sum1 = sum1 _;
        sum2 = sum2 _;
    }
    int sign = -1;
    if (N & 1) sign = 1;
    sum2 *= sign;
    if (N == 0) sum1 = nums[0];
    else sum1 = sum1 + sum2;
    sum1 = (sum1 + 1000000007)_;
    std::cout << sum1 << std::endl;




    return 0;
}