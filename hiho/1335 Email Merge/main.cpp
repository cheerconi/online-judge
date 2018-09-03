#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 10000 + 10;
int n;
int dad[MAXN];

int find(int i) {
    if (dad[i] == i) return i;
    return dad[i] = find(dad[i]);
}
void add(int i, int j) {
    int a = find(i);
    int b = find(j);
    dad[a] = b;
}
unordered_map<string, int> names;

bool cmp1 (vector<string> const & a, vector<string> const & b) {
    return names[a[0]] < names[b[0]];
}

bool cmp2 (string const & a, string const & b) {
    return names[a] < names[b];
}


int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) dad[i] = i;
    unordered_map<string, int> mails;
    int m;
    string name, mail;
    for (int i = 1; i <= n; i++) {
        cin >> name >> m;
        names.insert({name, i});
        for (int j = 0; j < m; j++) {
            cin >> mail;
            if (mails.find(mail) == mails.end()) {
                mails.insert({mail, i});
            }
            else {
                add(mails[mail], i);
            }
        }
    }
    unordered_map<int, vector<string>> um;
    for (auto it = names.begin(); it != names.end(); it++) {
        um[find(it->second)].push_back(it->first);
    }
    vector<vector<string> > ret;
    for (auto it = um.begin(); it != um.end(); it++) {
        ret.push_back(it->second);
    }

    for (vector<string>  & group : ret) {
        sort(group.begin(), group.end(), cmp2);
    }
    sort(ret.begin(), ret.end(), cmp1);

    for (vector<string> & group : ret) {
        for (int i = 0; i < group.size(); i++) {
            cout << group[i];
            if (i+1 == group.size()) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}