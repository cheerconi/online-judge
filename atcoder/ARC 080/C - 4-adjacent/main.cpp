#include <iostream>
using namespace std;

int main() {
//    freopen("test.txt", "r", stdin);
    int n, tmp;
    scanf("%d", &n);
    int cnt1 = 0, cnt4 = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if (tmp % 4 == 0) cnt4++;
        else if (tmp % 2 != 0) cnt1++;
    }
    if (cnt4 >= n-cnt4-1 || cnt4 >= cnt1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}