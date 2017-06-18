#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int compute(string h, string m) {
    string h_inv = h;
    reverse(h_inv.begin(), h_inv.end());
    if (h_inv == m) {
        return 0;
    }
    if (h_inv > m) {
        return stoi(h_inv) - stoi(m);
    }
    int cnt = 0;
    cnt = 60 - stoi(m);
    if (h == "23") return cnt;
    h = to_string(stoi(h)+1);
    reverse(h.begin(), h.end());
    cnt += stoi(h);
    return cnt;

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



    return 0;
}