#include <iostream>
#include <fstream>
using namespace std;

ifstream citire("input.in");
ofstream fout("output.out");

int main() {
    int a, b;

    citire >> a >> b;

    fout << "Salutare, folosesc fisiere !\n";
    return 0;
}