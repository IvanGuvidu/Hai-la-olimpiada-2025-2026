# Geometrie

Astăzi o să vorbim despre probleme de geometrie computațională.

De obicei, nu vom lucra în 3 dimensiuni, ci doar în 2D. Vom reprezenta punctele prin perechi de coordonate $(x, y)$. Știm foarte bine că distanța dintre două puncte este dată de formula: $\sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}$.

O să mai avem nevoie de formula pentru aria unui triunghi (cu semn), care este dată de:
$$
\text{Aria} = \begin{vmatrix}
x_1 & y_1 & 1 \\
x_2 & y_2 & 1 \\
x_3 & y_3 & 1
\end{vmatrix} = x_1(y_2 - y_3) + x_2(y_3 - y_1) + x_3(y_1 - y_2)
$$

Deseori, vom folosi semnul ariei pentru a determina poziția relativă a punctelor. Dacă $aria(x, y, z) > 0$, atunci putem spune că $z$ este "deasupra" dreptei formate de $x$ și $y$ (adică în sens trigonometric). Dacă $aria(x, y, z) < 0$, atunci $z$ este "dedesubtul" dreptei formate de $x$ și $y$. Dacă aria este 0, atunci cele 3 puncte sunt colineare.

## Înfășurătoare convexă

O problemă clasică de geometrie computațională este găsirea [înfășurătoarei convexe](https://infoarena.ro/problema/infasuratoare) a unui set de puncte. Înfășurătoarea convexă este cel mai mic poligon convex care conține toate punctele date. Pentru a găsi înfășurătoarea convexă, mai întâi, vom sorta punctele după coordonata $x$ (și în caz de egalitate, după coordonata $y$). Apoi, vom construi înfășurătoarea convexă în două părți: partea de jos(`lower_hull`) și partea de sus(`upper_hull`). Vom parcurge punctele sortate și vom încerca să adăugăm fiecare punct în ambele înfășurători. Dacă punctul curent este "sub" ultimul segment al determinat de ultimele două puncte din `lower_hull`, atunci vom elimina ultimul punct din `lower_hull` până când putem adăuga punctul curent. Similar, dacă punctul curent este "deasupra" ultimului segment al determinat de ultimele două puncte din `upper_hull`, vom elimina ultimul punct din `upper_hull` până când putem adăuga punctul curent. La final, vom concatena cele două înfășurători pentru a obține înfășurătoarea convexă completă.

```cpp
    while (sus.size() > 1 && arie(v[sus[sus.size() - 2]], v[sus.back()], v[i]) >= 0)
    {
        sus.pop_back();
    }
    while (jos.size() > 1 && arie(v[jos[jos.size() - 2]], v[jos.back()], v[i]) <= 0)        
    {
        jos.pop_back();
    }
    sus.push_back(i);
    jos.push_back(i);
```

Astfel, vom obține înfășurătoarea convexă în timp $O(n \log n)$ datorită sortării inițiale.

## Probleme și resurse

* [Mai multe despre geometrie - Infoarena](https://www.infoarena.ro/notiuni-de-geometrie-si-aplicatii)
* [Infasuratoare convexa - Infoarena](https://infoarena.ro/problema/infasuratoare)
* [Arhitect](https://kilonova.ro/problems/504)
* [Mosia](https://infoarena.ro/problema/mosia)
* [Gradina](https://infoarena.ro/problema/gradina)
* [Patrulatere](https://www.infoarena.ro/problema/patrulatere)
* [Oypara](https://www.infoarena.ro/problema/oypara)
* [Tramvaie](https://kilonova.ro/problems/2660?list_id=1079)

#### Cursul de azi a fost ținut de Ivan Andrei-Cristian.