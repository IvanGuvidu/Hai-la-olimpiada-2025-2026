# Centroid Decomposition, Componente Biconexe

## Centroid decomposition

În problemele de Divide et Impera, pleacam de la un șir și mereu îl împărțeam în două jumătăți, astfel încât să avem o complexitate $O(N log N)$. _Am putea_ încerca să folosim o abordare similară și asupra arborilor, dar cum am putea să împărțim un arbore în două jumătăți? Răspunsul este să folosim centroid decomposition.

Un centroid al unui arbore este un nod pe care, dacă îl eliminăm, toți subarborii rezultați au cel mult jumătate din nodurile arborelui original. Pentru a descompune intreg arborele, găsim un centroid, îl eliminăm, și apoi aplicăm recursiv aceeași procedură pe fiecare subarbore rezultat. Complexitatea acestei descompuneri este $O(N log N)$, deoarece fiecare nod este procesat de cel mult $O(log N)$ ori.

* [321C](https://codeforces.com/contest/321/problem/C)
* [342E](https://codeforces.com/contest/342/problem/E) - soluție [aici](xeniaandtree.cpp)
* [161D](https://codeforces.com/contest/161/problem/D)

## Componente biconexe, puncte de articulație, muchii critice

Un **punct de articulație** este un nod al grafului care, dacă este eliminat, crește numărul de componente conexe ale grafului. O **componentă biconexă** este o componentă conexa a unui graf care nu conține niciun punct de articulație. O **muchie critică** este o muchie a grafului care, dacă este eliminată, crește numărul de componente conexe ale grafului.

Cum detectăm o componentă biconexă? Putem folosi o parcurgere DFS, iar pentru fiecare nod vom reține timpul de descoperire ($tin$) și cel mai mic timp de descoperire al unui nod accesibil din subarborele său ($tmin$). Dacă pentru un nod $u$ există un copil $v$ în arborele DFS pentru care $tmin[v] \geq tin[u]$, atunci $u$ este un punct de articulație. De asemenea, dacă $tmin[v] > tin[u]$, atunci muchia $(u, v)$ este o muchie critică. Dacă, pentru un nod $u$, există un fiu $v$ pentru care $tmin[v] \geq tin[u]$, atunci, ce se află pe drum de la $u$ la $v$ este o componentă biconexa. O implementare a acestei idei poate fi găsită [aici](biconexe.cpp).

* [Componente biconexe (infoarena)](https://www.infoarena.ro/problema/biconex)
* [Clepsidra](https://infoarena.ro/problema/clepsidra)
* [Linegraph](https://infoarena.ro/problema/linegraph)
* [Regate](https://kilonova.ro/problems/138)

#### Cursul de azi a fost ținut de Ivan Andrei-Cristian.
