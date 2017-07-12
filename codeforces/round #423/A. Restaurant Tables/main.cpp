#include <iostream>
using namespace std;

int main() {
    int n, a, b, c = 0, tmp;
    scanf("%d%d%d",&n, &a, &b);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if (tmp == 1) {
            if (a > 0) a--;
            else if (c > 0) c--;
            else if (b > 0) {
                b--;
                c++;
            }
            else cnt++;
        }
        else {
            if (b > 0) b--;
            else cnt += 2;

        }
    }
    cout << cnt << endl;

    return 0;
}