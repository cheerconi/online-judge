#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;


int main() {
//    freopen("test.txt", "r", stdin);
    int n, g;
    cin >> n >> g;
    double goal = g;
    double single = (180*(n-2.0)) / n;
    single = (180 - single) / 2.0;
    int best = n;
    double angle = single;

    double dis = fabs(single - goal);
    int v1,v2,v3;
    v2 = 2;
    v3 = 1;
    v1 = n-1;
    while (v1 > v2) {
        angle += single;
        if (dis > fabs(angle-goal)) {
            dis = fabs(angle-goal);
            best = v1;
        }
        if (angle > goal) break;
        v1--;
    }
    cout << best << ' ' << v2 << ' ' << v3 << endl;


    return 0;
}