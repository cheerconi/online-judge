#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>

using namespace std;

vector<long long> digit(9, 0);
int big_pos(int i);
void find(int i, int j, int div);
void compute(int i, int j);

int big_pos(int i) {
    long pos = 10;
    while (i / pos) {
        pos *= 10;
    }
    pos /= 10;
    return pos;
}

void add(int start, int end) {

    int pos1 = big_pos(start);
    int d1 = start / pos1;
    digit[d1-1] += (d1+1)*pos1 - start;

    if (start == end) return;

    int pos2 = big_pos(end);
    int d2 = end / pos2;
    digit[d2-1] += end - pos2*d2;

    d1 += 1;
    start = d1 * pos1;
    end = d2 * pos2;
    while (start < end) {
        if (d1 == 10) {
            d1 = 1;
            pos1 *= 10;
        }
        digit[d1 - 1] += pos1;
        d1 += 1;
        start = d1 * pos1;
    }
    digit[d2-1]++;
}

void find(int i, int j, int div) {
    int start = 0;
    int end = 0;
    if (i % div == 0) start = i / div;
    else start = i/div+1;
    end = j / div;
    add(start, end);
    int pos = big_pos(div);
    int d = div / pos;
    digit[d-1] += end - start + 1;
    if (div*div == i) {
        digit[d-1]--;
    }
}

void compute(int i, int j) {
    for (int div = 1; div*div <= j; div++) {
        i = max(i, div*div);
        find(i, j, div);
    }
}

int main() {
    int i, j;
    cin >> i >> j;
    compute(i, j);

//    add(1,1000000000);
    for (int k = 0; k < 9; k++) cout << digit[k] << endl;


    return 0;
}