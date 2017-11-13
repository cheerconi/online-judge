#include <iostream>
using namespace std;
int data[110][2];

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> data[i][0] >> data[i][1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (data[j][0] < data[i][0] && data[i][1] < data[j][1]) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;


    return 0;
}