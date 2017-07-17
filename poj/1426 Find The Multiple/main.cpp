#include <iostream>
using namespace std;
typedef unsigned long long ULL;
ULL ret = 1;
bool dfs(int n) {
    if (ret % n == 0) {
        return true;
    }
    if ((ret*10)/10 != ret) {
        return false;
    }

    ret *= 10;
    if (dfs(n)) return true;
    ret |= 1;
    if (dfs(n)) return true;
    ret /= 10;
    return false;

}
int main() {
    int n;
    while (scanf("%d", &n)) {
        if (n == 0) break;
        ret = 1;
        dfs(n);
        cout << ret << endl;
    }


    return 0;
}