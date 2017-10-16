#include <iostream>
#include <vector>


using namespace std;

int main() {
//    freopen("test.txt", "r", stdin);
    int n, tmp;
    scanf("%d", &n);
    vector<int> ret(n, 0);
    int index = n/2;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        ret[index] = tmp;
        if (index > (n-1)/2) {
            index = n-1 - index;
        }
        else {
            index = n - 1 - ((n-i-1)/2-1);
        }
    }
    for (int num : ret) printf("%d ", num);
    cout << endl;
    return 0;
}