#include <iostream>
using namespace std;
const int MAXN = 110;
int prices[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }
    int i = m-2, j = m;
    int ret = -1;
    while (true) {
        if (i >= 0 && prices[i] <= k && prices[i]!=0) {
            ret = i;
            break;
        }
        if (j < n && prices[j] <= k && prices[j]!=0) {
            ret = j;
            break;
        }
        i--;
        j++;
    }
    cout << abs(ret-m+1)*10 << endl;
    return 0;
}