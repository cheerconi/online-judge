#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int MAXN = 200000 + 10;
const LL inf = 1e18;
int nums[MAXN];
LL dp[MAXN];
LL high, low;

void adjust() {
    if (low >= inf) {
        high += low / inf;
        low = low % inf;
    }
    else if (low < 0) {
        int k = 0;
        while (low < 0) {
            low += inf;
            k++;
        }
        high -= k;
    }
}

void print() {
    if (high == 0) {
        cout << low << endl;
        return;
    }
    if (high > 0) {
        printf("%I64d%018I64d\n", high, low);
        return;
    }
    if (low == 0) {
        printf("%I64d000000000000000000\n", high);
        return;
    }
    high++;
    low = inf - low;
    if (high == 0) {
        printf("-%I64d", low);
        return;
    }
    printf("%I64d%018I64d\n", high, low);
    return;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    unordered_map<int, int> table;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        table[nums[i]]++;
    }
    for (int i = n-1; i >= 0; i--) {
        dp[i] = dp[i+1] + nums[i];
    }
    for (int i = 0; i < n; i++) {
        table[nums[i]]--;
        low += dp[i+1] - 1LL * (n-i-1) * nums[i];
        adjust();

        LL cnt = table[nums[i]+1];
        low -= cnt;
        adjust();
        cnt = table[nums[i]-1];
        low += cnt;
        adjust();
    }
    print();

    return 0;
}