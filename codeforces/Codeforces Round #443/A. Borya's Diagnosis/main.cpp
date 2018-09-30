#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ret = 0;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (ret < a) ret = a;
        else {
            int tmp = (ret - a) / b + 1;
            ret = tmp*b + a;
        }
    }
    cout << ret << endl;
    return 0;
}