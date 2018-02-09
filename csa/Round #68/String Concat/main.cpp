#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int MAXN = 55;
bool ret[MAXN];
string ss[MAXN];

int main() {
    int n; cin >> n;
    map<string, vector<int> > table;
    for (int i = 1; i <= n; i++) {
        cin >> ss[i];
        table[ss[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            auto it = table.find(ss[i]+ss[j]);
            if (it != table.end()) {
                for (int k : it->second) ret[k] = true;
            }
            it = table.find(ss[j]+ss[i]);
            if (it != table.end()) {
                for (int k : it->second) ret[k] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ret[i]) cout << i << ' ';
    }
    cout << endl;
    return 0;
}