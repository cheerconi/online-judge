#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
int cnt[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int n, tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        cnt[tmp]++;
    }
    int ret = 0;
    for (int i = 0;i < MAXN; i++) {
        tmp = cnt[i];
        if (i+1 < MAXN) tmp += cnt[i+1];
        if (i-1 >= 0) tmp += cnt[i-1];
        ret = max(ret, tmp);
    }
    cout << ret << endl;
    return 0;
}