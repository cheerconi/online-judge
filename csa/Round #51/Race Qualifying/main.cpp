#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
const int MAXN = 1234;
stack<int> cls[MAXN];
int nums[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int n, tmp;
    scanf("%d", &n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        cls[tmp+i].push(i);
        m = max(m, tmp+i);
    }
    int k = 0;
    for (int i = 0; i <= m; i++) {
        while (!cls[i].empty()) {
            int pos = cls[i].top();
            cls[i].pop();
            nums[k++] = pos+1;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d", nums[i]);
        if (i == n-1) printf("\n");
        else printf(" ");
    }


    return 0;
}