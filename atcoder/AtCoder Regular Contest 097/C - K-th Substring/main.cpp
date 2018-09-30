#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int k; cin >> k;
    set<string> table;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 1; j <= 5; j++) {
            table.insert(s.substr(i,j));
        }
    }
    auto it = table.begin();
    for (int i = 1; i < k; i++) {
        it++;
    }
    cout << *it << endl;


    return 0;
}