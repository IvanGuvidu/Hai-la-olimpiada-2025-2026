#include <iostream>

using namespace std;

int n; 
bool ciur[101] = {1, 1};

// ciur[i] = 0 -> i e prim
// ciur[i] = 1 -> i NU e prim

int main() {
    
    // unordered_map<bool, int> ciur1;

    // for (int i = 0; i <= 100; ++i)
    //     cout << ciur[i] << '\n';

    // ciur[i] = 0 -> i e prim
    // ciur[i] = 1 -> i NU e prim

    ciur[0] = ciur[1] = 1;
    for (int i = 4; i <= 100; ++i)
        ciur[i] = 1;

        // se merge pana la sqrt(n), daca n nu e patrat perfect, 
        // calculati pana la urmatorul patrat perfect dupa n sau folositi i*i<=n
        for (int i = 3; i <= 10; i += 2) {
        if (ciur[i] == 0)
            for (int j = i * i; j <= 100; j += i)
                ciur[j] = 1;
    }
    for (int i = 1; i <= 100; ++i)
        cout << i << " " << (ciur[i] == 0 ? "prim" : "nu e prim") << '\n';
    return 0;
}