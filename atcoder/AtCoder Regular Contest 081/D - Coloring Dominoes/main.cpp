#include <iostream>
#include <string>
typedef long long LL;
using namespace std;
const int mod = 1000000007;


int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    string s1,s2;
    cin >> s1 >> s2;
    LL ret = 1;
    int ava = 3;
    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[i]) {
            ret = (ret * ava) % mod;
            ava = 2;
        }
        else {
            if (ava == 1) ret = (ret*3) % mod;
            else if (ava == 2) ret = (ret*2) % mod;
            else ret = (ret*6) % mod;
            ava = 1;
            i++;
        }
    }
    cout << ret << endl;
}