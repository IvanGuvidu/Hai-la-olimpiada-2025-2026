#include <iostream>
#include <vector>
using namespace std;


int main() {
    vector<int> a(10000, 1);
    cout << a.size() << ' ';
    cout << "Capacitate : " << a.capacity() << '\n';

    a.push_back(10); // adaugam o valoare
    cout << a.size() << ' '; // noua dimensiune
    cout << "Capacitate : " << a.capacity() << '\n';
    cout << *(a.end()) << '\n';

    // Aici ideea e ca size-ul se mareste cu 1, dar capacitatea se dubleaza
    // daca capacitatea initiala este depasita
    return 0;
}