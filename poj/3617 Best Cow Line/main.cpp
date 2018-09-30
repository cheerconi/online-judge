#include <iostream>
using namespace std;

const int MAXN = 2000 + 10;
char s[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c", &s[i]);
    }
    int cnt = 0;
    int i = 0, j = n-1;
    while (i <= j) {
        bool left = true;
        for (int k = 0; i+k < j-k; k++) {
            if (s[i+k] > s[j-k]) {
                left = false;
                break;
            }
            if (s[i+k] < s[j-k]) break;
        }
        if (left) printf("%c", s[i++]);
        else printf("%c", s[j--]);
        cnt++;
        if (cnt % 80 == 0) cout << endl;
    }
    if (cnt % 80 != 0) cout << endl;
    return 0;
}