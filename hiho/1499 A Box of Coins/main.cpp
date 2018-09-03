#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;
int a[MAXN];
int b[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i], &b[i]);
        sum += a[i] + b[i];
    }
    int avg = sum / (n << 1);
    LL cnt = 0;
    int flowa = 0, flowb = 0;
    for (int i = 0; i < n; i++) {
        a[i] += flowa;
        b[i] += flowb;
        cnt += abs(flowa) + abs(flowb);
        flowa = a[i] - avg;
        flowb = b[i] - avg;
        if ((LL)flowa*flowb < 0) {
            if (abs(flowa) >= abs(flowb)) {
                flowa += flowb;
                cnt += abs(flowb);
                flowb = 0;

            }
            else {
                flowb += flowa;
                cnt += abs(flowa);
                flowa = 0;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}