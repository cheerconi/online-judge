#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;

vector<LL> factor(int n) {
    vector<LL> ret(n+1, 1);
    for (int i = 1; i <= n; i++) {
        ret[i] = (ret[i-1]* (n-i+1)) / i;
    }
    return ret;

}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, p, tmp;
    scanf("%d%d", &n, &p);
    int one = 0;
    int two = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if (tmp & 1) one++;
        else two++;
    }
    vector<LL> factor_one = factor(one);
    vector<LL> factor_two = factor(two);

    LL ret1 = 0;
    LL ret2 = 0;
    for (int i = 0; i <= two; i++) {
        ret2 += factor_two[i];
    }
    if (p == 0) {

        for (int i = 0; i <= one; i+=2) {
            ret1 += factor_one[i];
        }
        cout << ret1*ret2 << endl;
    }
    else {
        for (int i = 1; i <= one; i+=2) {
            ret1 += factor_one[i];
        }
        cout << ret1*ret2 << endl;

    }
    return 0;
}