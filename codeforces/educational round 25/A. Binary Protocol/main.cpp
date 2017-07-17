#include <iostream>
using namespace std;
int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d",&n);
    int num = 0;
    int cnt = 0;
    char m;
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%c", &m);
        if (m == '1') {
            cnt++;
        }
        else { // m == '0'
            num = num*10 + cnt;
            cnt = 0;
        }
    }
    num = num * 10 + cnt;
    cout << num << endl;
    return 0;
}