#include <iostream>
using namespace std;
int main() {
    int s; cin >> s;
    int a, b, c;
    cin >> a >> b >> c;
    int tot = a + b + c;
    if (tot == 0) {
        cout << s << ' ' << 0 << ' ' << 0 << endl;
        return 0;
    }
    double unit = (double)s / tot;
    double x, y, z;
    x = unit * a;
    y = unit * b;
    z = unit * c;
    printf("%.10f %.10f %.10f\n", x, y, z);
}