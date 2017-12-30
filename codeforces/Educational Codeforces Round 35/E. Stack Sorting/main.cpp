#include <iostream>
#include <stack>
using namespace std;
const int MAXN = 200000 + 10;
int s[MAXN], nums[MAXN];
bool vis[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    int n, k, cur = 1, idx = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &nums[i]);
        vis[nums[i]] = true;
        if (nums[i] == cur) {
            cur++;
            while (idx > 0 && s[idx-1] == cur) {
                cur++;
                idx--;
            }
        }
        else {
            s[idx++] = nums[i];
        }
    }
    for (int i = 0; i+1 < idx; i++) {
        if (s[i] < s[i+1]) {
            cout << -1 << endl;
            return 0;
        }
    }
    int m = n;
    for (int i = 0; i < k; i++) {
        printf("%d", nums[i]); m--;
        if (m > 0) printf(" ");
        else printf("\n");
    }
    idx = 1;
    stack<int> ret;
    while (m > 0) {
        while (idx <= n && vis[idx]) idx++;
        while(idx <= n && !vis[idx]) ret.push(idx++);
        while (!ret.empty()) {
            printf("%d", ret.top()); ret.pop(); m--;
            if (m > 0) printf(" ");
            else printf("\n");
        }
    }

    return 0;
}