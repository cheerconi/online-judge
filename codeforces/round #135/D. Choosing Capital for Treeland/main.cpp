#include <iostream>
#include <vector>
using namespace std;

struct City{
    vector<int> sons;
    vector<bool> connect;
    int inner = 0;
    int outer = 0;

};
vector<City> cities;

void dfs_inner(int root, int dad) {
    int inner = 0;
    for (int i = 0; i < cities[root].sons.size(); i++) {
        int son_id = cities[root].sons[i];
        if (dad == son_id) continue;
        dfs_inner(son_id, root);
        inner += cities[son_id].inner + (!cities[root].connect[i]);
    }
    cities[root].inner = inner;
}
void dfs_outer(int root, int dad) {
    for (int i = 0; i < cities[root].sons.size(); i++) {
        int son_id = cities[root].sons[i];
        if (son_id == dad) continue;
        int outer = cities[root].inner - cities[son_id].inner - (!cities[root].connect[i]);
        outer += cities[root].outer + (cities[root].connect[i]);
        cities[son_id].outer = outer;
        dfs_outer(son_id, root);
    }
}


int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    cities = vector<City>(n+1, City());
    for (int i = 2; i <= n; i++) {
        int s,t;
        scanf("%d%d", &s, &t);
        cities[s].sons.push_back(t);
        cities[s].connect.push_back(true);

        cities[t].sons.push_back(s);
        cities[t].connect.push_back(false);

    }
    dfs_inner(1,0);
//    for (int i = 1; i <= n; i++) cout << cities[i].inner << ' ';
//    cout << endl;
    dfs_outer(1,0);
//    for (int i = 1; i <= n; i++) cout << cities[i].outer << ' ';
//    cout << endl;
    vector<int> ret;
    int m = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int val = cities[i].outer + cities[i].inner;
        if (m > val) {
            ret.clear();
            ret.push_back(i);
            m = val;
        }
        else if (m == val) {
            ret.push_back(i);
        }
    }
    printf("%d\n", m);
    for (int i = 0; i < ret.size(); i++) {
        printf("%d", ret[i]);
        if (i == ret.size() -1) printf("\n");
        else printf(" ");
    }
    return 0;
}