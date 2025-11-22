#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("sirr11.in");
ofstream fout("sirr11.out");


int n;

int main() {
    fin >> n;

    for (int i = n; i >= 1; --i) {
        fout << (i % 2 == 0 ? -(i / 2) : (i + 1) / 2) << ' ';
    }

    return 0;
}