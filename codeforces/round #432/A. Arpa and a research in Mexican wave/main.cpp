#include <iostream>
using namespace std;
typedef long long LL;

int main() {
//    freopen("test.txt", "r", stdin);
    int n, k, t;
    scanf("%d%d%d", &n, &k, &t);
    LL end = min(n, t);
    LL start = max((LL)t-k, 0LL);
    cout << end - start << endl;
    return 0;
}