#include <iostream>
#include <bitset>
using namespace std;
typedef long long LL;
const int MAXN = 1000000 + 10;
int cnt[MAXN];
int main() {
    int n;
    cin >> n;
    cnt[0] = 1;
    int val = 0, sum = 0;
    LL ret = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        sum += val;
        for (int j = 0; j <= 1000; j++) {
            if (sum-j*j < 0) break;
            ret += cnt[sum-j*j];
        }
        cnt[sum]++;
    }
    cout << ret << endl;
}