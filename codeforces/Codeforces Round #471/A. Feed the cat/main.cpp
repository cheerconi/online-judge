#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int hh, mm;
    cin >> hh >> mm;
    int h, d, c, n;
    cin >> h >> d >> c >> n;
    int dist = 0;
    while (hh < 20) {
        dist++;
        mm++;
        if (mm == 60) {
            mm = 0;
            hh++;
        }
    }
    int cnt1 = h / n;
    if (h % n != 0) cnt1++;
    double ret1 = (double)cnt1*c;
    h = (h+dist*d);
    int cnt2 = h / n;
    if (h % n != 0) cnt2++;
    double ret2 = (double)cnt2*c*0.8;
    printf("%.10f\n", min(ret1, ret2));

    return 0;
}