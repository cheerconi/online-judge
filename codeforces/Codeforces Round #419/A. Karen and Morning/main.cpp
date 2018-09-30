#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

bool check(int i, int j) {
    string h = to_string(i);
    if (h.size() == 1) h = "0" + h;
    string m = to_string(j);
    if (m.size() == 1) m = "0" + m;
    if (h[0] != m[1]) return false;
    if (h[1] != m[0]) return false;
    return true;

}

int compute(string h, string m) {
    int hh = stoi(h);
    int mm = stoi(m);
    int cnt = 0;
    while (true) {
        if (check(hh, mm)) return cnt;
        mm += 1;
        if (mm == 60) {
            mm = 0;
            hh += 1;
        }
        if (hh == 24) hh = 0;
        cnt++;
    }


}

using namespace std;

int main() {
    //freopen("test.txt", "r", stdin);
    string time;
    cin >> time;
    string h = time.substr(0,2);
    string m = time.substr(3);

    int cnt = compute(h, m);
    cout << cnt << endl;

//    for (int i = 0; i < 24; i++) {
//        for (int j = 0; j < 60; j++) {
//            string tmp1 = to_string(i);
//            if (tmp1.size() == 1) tmp1 = "0"+tmp1;
//            string tmp2 = to_string(j);
//            if (tmp2.size() == 1) tmp2 = "0"+tmp2;
//            int cnt = compute(tmp1, tmp2);
//            cout << tmp1 << ":" << tmp2 << "\t" << cnt << endl;
//
//        }
//    }



    return 0;
}