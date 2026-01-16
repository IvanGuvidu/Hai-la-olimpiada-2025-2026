
# Aritmetică modulară & Probleme diverse #2


## Invers modular


De multe ori, când lucrăm cu aritmetică modulară, o să facem multe operații de adunare, scădere, înmulțire și împărțire.


Adunarea și înmulțirea merg destul de simplu făcute


$$
(a + b) \bmod M
$$
$$
(a \cdot b) \bmod M
$$


Pentru scădere, mai întâi, vom presupune că ambele numere sunt în intervalul $[0, M-1]$, și atunci putem face:

$$
(a - b + M) \bmod M
$$


Trebuie avut grijă să adăugăm $M$ înainte de a face modulo, pentru a evita rezultatele negative.
Probleme mari apar însă la împărțire. Dacă vom dori să facem $\frac{a}{b} \ \% \ M$, nu putem face direct:


$$
(a \div b) \bmod M
$$


Vom rescrie acest calcul ca fiind 

$$
a \cdot b^{-1} \bmod M
$$


unde $b^{-1}$ este **inversul modular** al lui $b$ modulo $M$.


Vom trata doar cazul în care $M$ este prim. În acest caz, inversul modular al lui $b$ modulo $M$ poate fi calculat folosind **mica teoremă a lui Fermat**.

$$
b^{-1} \equiv b^{M-2} \pmod{M}
$$


Fiindcă $M$ este un număr de obicei mare, vom calcula $b^{M-2} \bmod M$ folosind **exponentierea rapidă**.

În probleme, o să întâlnim deseori împărțirile la calculul combinărilor. Cum nu este deloc eficient să calculăm inversul modular al factorialelor, vom face următoarea precalculare:


$$
fact[i] = (fact[i-1] \cdot i) \bmod M, \text{pentru } 1 \leq i \leq \textbf{n + 1}
$$


$$
invFact[n + 1] = lgput(fact[n + 1], M - 2)
$$


$$
invFact[i] = (invFact[i + 1] \cdot (i + 1)) \bmod M, \text{pentru } n \geq i \geq 1
$$


## Probleme

* [Bob](https://kilonova.ro/problems/81?list_id=7)
* [Gard2](https://infoarena.ro/problema/gard2)
* [Nmult](https://kilonova.ro/problems/1468?list_id=593)
* [Cromatic](https://kilonova.ro/problems/3616?list_id=1385)
* [Blis](https://kilonova.ro/problems/37?list_id=3)
* [Dragonfruit](https://kilonova.ro/problems/1603?list_id=557)
* [Zid](https://kilonova.ro/problems/2651/)


#### Cursul de azi a fost ținut de Ivan Andrei-Cristian.