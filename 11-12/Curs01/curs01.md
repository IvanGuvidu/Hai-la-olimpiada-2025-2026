# Intro

Salutare și bine ați venit la o nouă ediție a cursurilor _Hai la Olimpiadă!_

Anul acesta vom parcurge împreună materia pentru clasele 11-12. Programa pentru olimpiadă se poate găsi [aici](https://cdn.sepi.ro/oni2024/Programa%20pentru%20olimpiada%20de%20informatica_gimnaziu%20si%20liceu.pdf).

În principiu, noi vom lucra probleme de pe următoarele site-uri:

* [Infoarena](https://infoarena.ro/)
* [Kilonova](https://kilonova.ro/)
* [Codeforces](https://codeforces.com/)
* [CSES](https://cses.fi/)

Suportul teoretic pentru curs va fi inspirat din următoarele resurse:

* [Infoarena - Arhiva Educațională](https://infoarena.ro/arhiva-educationala)
* [CP-algorithms](https://cp-algorithms.com/)
* [USACO guide](https://usaco.guide/)

Listele cu toate probleme pentru OJI/ONI le găsiți mai jos:

* [OJI](https://kilonova.ro/problem_lists/459/progress)
* [ONI](https://kilonova.ro/problem_lists/528/progress)

Stilul meu de predare este să acoperim noțiuni teoretice la curs, discutăm probleme, iar implementările de la problemele discutate vă rămân vouă ca temă pentru acasă. Consider că în acest mod putem să abordăm mai multe probleme în cele două ore pe care le avem noi săptămânal.

O să încercăm (sperăm) lunar să vă dăm câte o simulare cu probleme adecvate de OJI-ONI.

# Backtracking

De multe ori, când vrem să formulăm o soluție la o problemă, nu putem formula soluții care să fie în timp polinomial. De exemplu, dacă trebuie să generăm toate permutarile unui șir, acest lucru se poate realiza numai printr-un algoritm exponențial. Aici apar algoritmii de **Backtracking**: ei generează absolut toate soluțiile posibile pentru o problemă, iar peste ele poate reușim să le prelucrăm într-un mod mai avantajos. Pentru doritori, puteți citi despre una dintre cele mai mari [dileme](https://en.wikipedia.org/wiki/P_versus_NP_problem) nerezolvate ale algoritmicii moderne.

## Generarea de submulțimi

De obicei, Backtracking-ul are două clase de algoritmi:

* algoritmi de complexitate **exponențială**
* algoritmi de complexitate **factorial**

Algoritmii de complexitate exponențială, de obicei, au la bază generarea de submulțimi. Ca exemplu, aveți funcția din sursa [`expo.cpp`](https://github.com/IvanGuvidu/Hai-la-olimpiada-2025-2026/blob/main/11-12/Curs01/expo.cpp) atașată mai jos:

```cpp
void bkt (int k, int n)
{
    if (k == n + 1)
    {
        afis();
        return;
    }
    pos++;
    v[pos] = k;
    bkt(k + 1, n);
    pos--;
    bkt(k + 1, n);
}
```

Această funcție va genera toate submulțimile ordonate lexicografic ale mulțimii $\{1, 2, \dots, N\}$. Acest algoritm va avea complexitate $O(2^N)$. De obicei, acești algoritmi vor intra în limita de timp dacă $N \leq 22$.

## Generarea de permutări

Algoritmii de complexitate factorială au la bază generarea de permutări. O implementare aveți în funcția [`factorial.cpp`](https://github.com/IvanGuvidu/Hai-la-olimpiada-2025-2026/blob/main/11-12/Curs01/factorial.cpp), pe care o găsiți mai jos:

```cpp
void bkt (int k)
{
    if (k == n + 1)
    {
        afis();
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (uz[i] == 0)
        {
            v[k] = i;
            uz[i] = 1;
            bkt(k + 1);
            uz[i] = 0;
        }
    }
}
```
Această funcție va genera toate permutările ordonate lexicografic ale mulțimii $\{1, 2, \dots, N\}$. Acest algoritm va avea complexitate $O(N!)$. De obicei, acești algoritmi vor intra în limita de timp dacă $N \leq 10$.

## Probleme

* [Permutări](https://infoarena.ro/problema/permutari)
* [Bile](https://kilonova.ro/problems/1304)
* [Flip](https://infoarena.ro/problema/flip)
* [Elimin](https://infoarena.ro/problema/elimin)
* [Dușman](https://infoarena.ro/problema/dusman)
* [Tricouri](https://infoarena.ro/problema/tricouri)

## Probleme suplimentare

* [Zone](https://infoarena.ro/problema/zone)
* [Proeminența](https://kilonova.ro/problems/1598)

#### Cursul de azi a fost ținut de Ivan Andrei-Cristian.