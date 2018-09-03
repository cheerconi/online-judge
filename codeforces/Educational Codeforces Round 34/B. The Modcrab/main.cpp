#include <iostream>
#include <vector>
using namespace std;
vector<bool> fight;
int main() {
    int h1, a1, c1, h2, a2;
    cin >> h1 >> a1 >> c1 >> h2 >> a2;
    while (true) {
        if (h1 > a2 || h2 <= a1) {
            fight.push_back(true);
            h2 -= a1;
        }
        else {
            fight.push_back(false);
            h1 += c1;
        }
        h1 -= a2;
        if (h2 <= 0) break;
    }
    cout << fight.size() << endl;
    for (bool flag : fight) {
        if (flag) cout << "STRIKE" << endl;
        else cout << "HEAL" << endl;
    }
    return 0;
}