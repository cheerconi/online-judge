#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

static const int MAXC = 1000000 + 1;

int main() {
//    freopen("test.txt", "r", stdin);
    int n, alice;
    scanf("%d%d", &n, &alice);
    vector<int> cars(MAXC, 0);
    int threshold = 0;

    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp == alice) {
            threshold++;
            continue;
        }
        if (cars[tmp] < threshold) cars[tmp] = -1;
        else {
            cars[tmp]++;
        }
    }

    for (int i = 1; i < MAXC; i++) {
        if (i == alice) continue;
        if (cars[i] < threshold) continue;
        cout << i << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;


}
