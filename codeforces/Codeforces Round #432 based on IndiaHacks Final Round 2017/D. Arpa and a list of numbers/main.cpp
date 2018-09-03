#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
int n, x, y;
const int MAXV = 1e6 + 10;
const int MAXN = 5e5 + 10;
const LL inf = 0x7fffffffffffffff;
vector<int> primes;
int cnt[MAXV];
LL sum[MAXV];


void make_table() {
    vector<bool> tmp(MAXV, true);
    for (int i = 4; i < MAXV; i += 2) tmp[i] = false;
    for (int i = 3; i < MAXV; i += 2) {
        if (!tmp[i]) continue;
        for (int j = i+i; j < MAXV; j += i) {
            tmp[j] = false;
        }
    }
    for (int i = 2; i < MAXV; i++) {
        if (tmp[i]) primes.push_back(i);
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    make_table();
    int n, x, y, num, val = 0;
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        cnt[num]++;
        sum[num] += num;
        val = max(val, num);
    }
    for (int i = 1; i <= val; i++) {
        cnt[i] += cnt[i-1];
        sum[i] += sum[i-1];
    }
    LL ret = inf;
    int mid = x/y;

    for (int p : primes) {
        LL cur = 0;
        for (int i = 0; i <= val; i += p) {
            int ind1 = i+p-1;
            if (ind1 > val) ind1 = val;
            int ind2 = i+p - min(p-1, mid) -1;
            if (ind2 > val) ind2 = val;
            LL card = cnt[ind1] - cnt[ind2];
            cur += (card*(p+i) - sum[ind1] + sum[ind2]) * y;
            cur += (cnt[ind2] - cnt[i]) * (LL)x;
            if (cur > ret) break;
        }
        ret = min(ret, cur);
    }
    cout << ret << endl;


}