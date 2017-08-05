#include <iostream>
#include <algorithm>
using namespace std;

int main() {
//    freopen("test.txt", "r",stdin);
    char c;
    int n;
    scanf("%d", &n);
    getchar();
    int cur = 0;
    int ret = -1;
    for (int i = 0; i < n; i++) {
        scanf("%c", &c);
        if (c == ' ') {
            ret = max(ret, cur);
            cur = 0;
        }
        else if (c >= 'A' && c <= 'Z') cur++;
    }
    ret = max(ret, cur);
    cout << ret << endl;
    return 0;
}