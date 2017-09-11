#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <memory.h>
using namespace std;
const int MAXN = 110;
int nums[MAXN];
bool bad[1000000+1];
int ret[MAXN];
int n;

int solve() {
    set<int> dis;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            dis.insert(abs(nums[i]-nums[j]));
        }
    }
    memset(bad, 0, sizeof(bad));
    int sz = 0;
    for (int i = 1; i <= 1000000 && sz < n; i++) {
        if (bad[i]) continue;
        ret[sz++] = i;
        for (int d : dis) {
            bad[d+i] = true;
        }
    }
    return sz;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int sz = solve();
        if (sz == n) {
            printf("YES\n");
            for (int i = 0; i < n; i++) {
                printf("%d", ret[i]);
                if (i == n-1) printf("\n");
                else printf(" ");
            }
        }
        else {
            printf("NO\n");
        }

    }
}