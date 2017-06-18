#include <iostream>
#include <vector>

using namespace std;

const int MAX = 200002;

int main() {
    //freopen("test.txt", "r", stdin);
    int n,k,q;
    cin >> n >> k >> q;
    vector<int> ref(MAX, 0);
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        ref[a]++;
        ref[b+1]--;
    }
    for (int i = 1; i < MAX; i++) {
        ref[i] += ref[i-1];
    }
    vector<int> data(MAX, 0);
    for (int i = 1; i < MAX; i++) {
        if (ref[i] >= k) data[i]++;
        data[i] += data[i-1];
    }
    while(q--) {
        int a,b;
        cin >> a >> b;
        cout << data[b] - data[a-1] << endl;
    }


    return 0;
}