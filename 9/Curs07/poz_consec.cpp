#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("pozitiiconsecutive.in");
ofstream fout("pozitiiconsecutive.out");

int x, y, a = 1;

// a x y
// x y 


int main() {
    fin >> x >> y;
    fout << y << ' ' << x << ' ';

    while (a != 0) {
        a = 2 * x - y + 2;
        fout << a << ' ';
        y = x;
        x = a;
    }
    return 0;
}