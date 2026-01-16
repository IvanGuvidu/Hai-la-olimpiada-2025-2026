
# Aritmetică modulară & Probleme diverse #2


## Invers modular


De multe ori, când lucrăm cu aritmetică modulară, o să facem multe operații de adunare, scădere, înmulțire și împărțire.


Adunarea și înmulțirea merg destul de simplu făcute

$$
(a + b) \ \% \ mod
$$
$$
(a \cdot b) \ \% \ mod
$$


Pentru scădere, mai întâi, vom presupune că ambele numere sunt în intervalul $[0, mod-1]$, și atunci putem face:

$$
(a - b + mod) \ \% \ mod
$$


Trebuie avut grijă să adăugăm $mod$ înainte de a face modulo, pentru a evita rezultatele negative.


Probleme mari apar însă la împărțire. Dacă vom dori să facem $\frac{a}{b} \ \% \ m$, nu putem face direct:

$$
(a \div b) \ \% \ mod
$$


Vom rescrie acest calcul ca fiind 
$$
a \cdot b^{-1} \ \% \ mod
$$


unde $b^{-1}$ este **inversul modular** al lui $b$ modulo $mod$.


Vom trata doar cazul în care $mod$ este prim. În acest caz, inversul modular al lui $b$ modulo $mod$ poate fi calculat folosind **mica teoremă a lui Fermat**:

$$
b^{-1} \equiv b^{mod-2} \ \% \ mod
$$


Fiindcă $mod$ este un număr de obicei mare, vom calcula $b^{mod-2} \ \% \ mod$ folosind **exponentierea rapidă**.


În probleme, o să întâlnim deseori împărțirile la calculul combinărilor. Cum nu este deloc eficient să calculăm inversul modular al factorialelor, vom face următoarea precalculare:

$$
fact[i] = (fact[i-1] \cdot i) \ \% \ mod, \text{pentru } 1 \leq i \leq \textbf{n + 1}
$$

$$
invFact[n + 1] = lgput(fact[n + 1], mod - 2)
$$

$$
invFact[i] = (invFact[i + 1] \cdot (i + 1)) \ \% \ mod, \text{pentru } n \geq i \geq 1
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