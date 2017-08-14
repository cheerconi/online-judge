#include <iostream>
#include <algorithm>
using namespace std;

int one, two, four;

bool solve(int a) {
    if (a == 0) return true;
    int save = a;
    int tmp = a / 4;
    a = a - 4 * min(tmp, four);
    four = four - min(tmp, four);
    tmp = a / 2;
    a = a - 2 * min(tmp, two);
    two = two - min(tmp, two);
    if (four > 0 && a == 3) {
        a = 0;
        four--;
    }
    else if (four > 0 && a == 2) {
        a = 0;
        four--;
        one++;
    }
    else if (four > 0 && a == 1) {
        a = 0;
        four--;
        two++;
    }
    else if (two > 0 && a == 1) {
        a = 0;
        two--;
    }
    if (a == save) {
        tmp = a;
        a = a - min(tmp, one);
        one = one - min(tmp, one);
    }
    if (a == save) return false;
    return solve(a);
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, k, a;
    scanf("%d%d", &n, &k);
    two = n*2;
    four = n;
    for (int i = 0; i < k; i++) {
        scanf("%d", &a);
        if (!solve(a)) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;

}