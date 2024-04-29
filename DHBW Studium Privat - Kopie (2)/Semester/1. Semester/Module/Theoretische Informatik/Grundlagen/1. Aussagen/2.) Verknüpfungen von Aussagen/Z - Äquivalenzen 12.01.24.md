
|  | *Äquivalenzarten* | *Beispiele* |
| ---: | :--- | ---- |
| - | *Kommatativität:* | $F \wedge G \equiv G \wedge F \; , \; F \vee G \equiv G \vee F$ |
| - | *Assoziativität:* | $F  \wedge (G \wedge H ) \equiv (F \wedge G) \wedge H \; , \; F \vee (G \vee H) \equiv (F \vee G) \wedge H$ |
| - | *Distributivität:* | $F \wedge (G \wedge H) \equiv (F \wedge G) \vee (F \wedge H) \; , \; F \vee (G \wedge H) \equiv (F \vee G) \wedge (F \vee H)$ |
| - | *Idempotenz:* | $F \wedge F \equiv F \; , \; F \vee F \equiv F$ |
| - | *Doppelte Neagtion:* | $\neg (\neg F) \equiv F$ |
| - | *Regeln von de Morgen:* | $\neg (F \wedge G) \equiv (\neg F) \vee (\neg G) \; , \; \neg (F \vee G) \equiv (\neg F) \wedge (\neg G)$ |
| - | *Tautologieregel:* | $F \wedge w \equiv F \; , \; F \vee w \equiv w$ |
| - | *Kontratdikationregel:* | $F \vee f \equiv F \; , \; F \wedge f \equiv f$ |

## Beispiel - Vereinfachen

|  |  |  |  |
| ---- | ---- | ---- | ---- |
| $\neg (\neg p \wedge q) \wedge (p \vee q)$ | $\equiv$ | $((\neg \neg p) \vee (\neg q)) \wedge (p \vee q)$ | *de Morgan*  |
|  | $\equiv$ | $(p \vee (\neg q)) \wedge (p \vee q)$ | *doppelte Negation* |
|  | $\equiv$ | $p \vee ( \neg q \wedge q)$ | *Distribtution* |
|  | $\equiv$ | $p \vee f$ | *Prinzip vom ausgeschlossenen Wiederspruch* |
|  | $\equiv$ | $p$ | Kontratdikationsregel |
