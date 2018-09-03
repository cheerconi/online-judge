#include <iostream>
#include <memory.h>
static const int MAXN = 200000 + 10;
int cnt[MAXN];
int cover[MAXN];
int a[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    memset(cnt, 0, sizeof(cnt));
    memset(cover, 0, sizeof(cover));
    int n, m;
    scanf("%d%d", &n, &m);
    int ret = n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        int tmp = a[i] - cnt[a[i]];
        if (tmp < 1) tmp = 1;
        cover[tmp]++;
        if (cover[tmp] == 1) ret--;
        cnt[a[i]]++;
    }
    int index, val;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &index, &val);
        if (a[index] == val) {
            printf("%d\n", ret);
            continue;
        }
        int num = cnt[a[index]];
        int tmp = a[index] - num + 1;
        if (tmp < 1) tmp = 1;
        cover[tmp]--;
        if (cover[tmp] == 0) ret++;
        cnt[a[index]]--;
        tmp = val - cnt[val];
        if (tmp < 1) tmp = 1;
        cover[tmp]++;
        if (cover[tmp] == 1) ret--;
        cnt[val]++;
        printf("%d\n", ret);
        a[index] = val;
    }

    return 0;
}