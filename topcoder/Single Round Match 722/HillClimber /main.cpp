#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct  HillClimber {
    int longest(vector <int> height) {
        int cnt = 0;
        int ret = 0;
        int n = height.size();
        for (int i = 1; i < n; i++) {
            if (height[i] > height[i-1]) cnt++;
            else {
                ret = max(ret, cnt);
                cnt = 0;
            }
        }
        ret = max(ret, cnt);
        return ret;
    }

};


int main() {
    vector<int> height{ 1, 2, 3, 2, 2 };
    HillClimber test = HillClimber();
    cout << test.longest(height) << endl;


}