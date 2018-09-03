#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct Item{
    string name, prev, rear, data;
    bool operator< (const Item & oth) const {
        int c = stoi(prev), d = stoi(oth.prev);
        if (c != d) return c > d;
        int i = 0;
        for (; i < min((int)rear.size(), (int)oth.rear.size()); i++) {
            if (rear[i] == oth.rear[i]) continue;
            return rear[i] > oth.rear[i];
        }
        if (i < rear.size()) {
            return true;
        }
        if (i < oth.rear.size()) {
            return false;
        }
        return name < oth.name;
    }
    Item(string _name, string point) {
        data = _name + " " + point;
        name = _name;
        int i = 0;
        while (i < point.size() && point[i] != '.') {
            prev.push_back(point[i++]);
        }
        i++;
        while (i < point.size()) {
            rear.push_back(point[i++]);
        }
        while (!rear.empty() && rear.back() == '0') rear.pop_back();
    }
};

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<Item> v;
    string a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back(Item(a, b));
    }
    sort(v.begin(),v.end());
    for (auto & item : v) {
        cout << item.data << '\n';
    }
    return 0;
}