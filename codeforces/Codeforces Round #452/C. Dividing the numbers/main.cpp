#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
typedef long long LL;
vector<int> ret;
void solve (LL n) {
    LL sum = (n+1)*n / 2;
    if (sum % 2 == 0) cout << 0 << endl;
    else cout << 1 << endl;
    LL sum1 = 0, sum2 = 0;
    for (int i = n; i >= 1; i--) {
        if (sum1 > sum2) {
            sum2 += i;
        }
        else {
            sum1 += i;
            ret.push_back(i);
        }
    }
    assert(sum1+sum2 == sum);

}
int main() {
    int n;
    cin >> n;
    solve(n);
    cout << ret.size() << ' ';
    for (int i = 0; i < ret.size(); i++) {
        printf("%d", ret[i]);
        if (i+1 == ret.size()) cout << endl;
        else printf(" ");
    }
    return 0;
}