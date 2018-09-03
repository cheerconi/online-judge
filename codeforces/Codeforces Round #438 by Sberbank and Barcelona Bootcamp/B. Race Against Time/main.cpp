#include <iostream>
#include <algorithm>
using namespace std;
int pos[3];

int main() {
//    freopen("test.txt", "r", stdin);
    int h, m, s, t1, t2;
    cin >> h >> m >> s >> t1 >> t2;
    pos[2] = s * 60 * 12;
    pos[1] = (m * 60 + s) * 12;
    if (h == 12) h = 0;
    pos[0] = h * 3600 + 60*m + s;
    sort(pos, pos+3);
    if (t1 == 12) t1 = 0;
    if (t2 == 12) t2 = 0;
    t1 *= 3600;
    t2 *= 3600;
    for (int i = 0; i < 2; i++) {
        if (t1 > pos[i] && t2 > pos[i] && t1 < pos[i+1] && t2 < pos[i+1]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    if ((t1 < pos[0] || t1 > pos[2]) && (t2 < pos[0] || t2 > pos[2])) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}