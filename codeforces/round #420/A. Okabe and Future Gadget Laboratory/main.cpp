#include <iostream>
#include<unordered_set>
#include <vector>
#include <map>

static const int MAXN = 50 + 5;



using namespace std;

int main() {
//    freopen("test.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    multimap<int, pair<int,int> > items;
    vector<unordered_set<int> > rowset(N+1, unordered_set<int>());
    vector<unordered_set<int> > colset(N+1, unordered_set<int>());

    int item;
    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= N; col++) {
            scanf("%d", &item);
            if (item != 1) {
                items.insert({item, {row, col}});
            }
            rowset[row].insert(item);
            colset[col].insert(item);
        }
    }
    for (auto it = items.begin(); it != items.end(); it++) {
        int val = it->first;
        int x = it->second.first;
        int y = it->second.second;
        bool flag = false;
        for (int tmp : rowset[x]) {
            auto it_tmp = colset[y].find(val - tmp);
            if (it_tmp != colset[y].end()) {
                flag = true;
                break;
            }
        }
        if (! flag) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;

}