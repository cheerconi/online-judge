#include <iostream>
using namespace std;
const int MAXN = 100 + 10;
bool nums[MAXN];

int main() {
    int n, x, tmp;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        nums[tmp] = true;
    }
    int cnt = 0;
    for (int i = 0; i < x; i++) {
        if (!nums[i]) cnt++;
    }
    if (nums[x]) cnt++;
    cout << cnt << endl;

    return 0;
}