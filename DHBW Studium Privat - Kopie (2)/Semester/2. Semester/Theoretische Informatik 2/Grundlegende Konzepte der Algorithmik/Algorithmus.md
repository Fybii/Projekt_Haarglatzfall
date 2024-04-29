**Frage:** was ist ein **Algorithmus?**
**Andere Frage:** Was ist das Ziel der **Algorithmen-Theorie?**

- Letztendlich geht es um eine **Definition** der **berechenbaren Funktionen.**
	- Dies gelingt exakt in der **Berechenbarkeitstheorie** und der **Koplexitätstheorie**.
	- $\Rightarrow$ **Algorithmen** sind **pseudo formale Formulierungen berechenbarer Funktionen**

## Der Berechenbarkeitsbegriff 
- **Alan Turing** erfand 1936 das Modell der **Turingmaschine**.
- **Alonso Church** entwickelte 1932 den **$\lambda$-Kalkül**.
- Der **Formalismus** der **µ-rekursiven Funktionen.** (Skolem 1923, Stephen C. Kleene 1936,...)
- **Weitere Berechnungsmodelle:** *Registermaschinen, WHILE-Programme,...*
- Beschränkt man sich auf **Funktionen natürlicher Zahlen**, sind alle **oben aufgeführten Berechenbarkeitsmodelle *äquivalent***.

## Algorithmenanalyse

- Ein **Algorithmus** $A$ wird immer mit einer **Eingabe** **gestartet**.
- Die **Eingabe** kann eine **Zahl**, ein **Graph**, eine **Matrix**, eine **Zeichenkette**, ... sein.
- Jeder **Eingabe** $x$ muss eine **Länge** $\mid x \mid$ **zugeordnet** **werden**.
- Es sei $time(A,x)$ die **Laufzeit** des **Algorithmus** $A$ bei **Eingabe** $x$:
	- Wir betrachten den **schlechtesten**, sowie den **mittleren** **Fall** der **Laufzeit** $A$ in **Abhängigkeit** der **Länge** $n$ der **Eingabe**:
		- **worst-case** **Komplexität**: $T_{wc}(A,n) = max\{time(A,x) \mid \; \mid x \mid = n\}$ Dies ist die **maximale** **Laufzeit** $A$ bei einer **Eingabe** der **Länge** $n$.
		- **average-case Komplexität**: $T_{ac}(A,n)=\frac{\sum^{}_{x: \mid x \mid =n} time(A,x)}{\mid \{x \; \mid \; \mid x \mid = n \} \mid}$ Dies ist die **mittlere** **Laufzeit** von $A$ bei einer **Eingabe** der **Länge** $n$. Dabei wird jede **Eingabe** der **Länge** $n$ **gleich** **gewichtet**.
		- Es **gilt** **immer** $T_{ac}(A,n) \leq T_{wc}(A,n)$
		

| $x$   | $time(A,x)$ |
| ----- | ----------- |
| $a$   | $1$         |
| $b$   | $1$         |
| $aa$  | $2$         |
| $ab$  | $3$         |
| $ba$  | $3$         |
| $bb$  | $4$         |
| $aaa$ | $5$         |
| $aab$ | $5$         |
$$
\begin{align}
\{ x \mid \; \mid x \mid = 2 \} &= \{aa,ab,ba,bb\} \\
\mid \ldots \mid &= 4 \\
\sum^{}_{x: \mid x \mid = 2} time(A,x) &= 2+3+3+4 = 12 \\
\Rightarrow T_{ac}(A,2) &= \frac{12}{4} = 3 
\end{align}
$$ 

### Beispiel
- **Berechnung** des **Maximus** einer **Folge** **natürlicher** **Zahlen**
```Pseudo
Function Max(a[1,...,n] : N) : N
	m = a[1]
	i = 2
	while i <= n do
		if a[i] > m then
			m := a[i]
		else
			NoP
		i++
	return m
```
- **Bestimme** folgende **Aufwände**:
	- **Sei** $c_1$ der **Aufwand** für die **Ausführung** der **Zeile** **02** und **03**,
	- $c_2$ der **Aufwand** für den **Test** in **Zeile** **04**,
	- $c_3$ der **Aufwand** für **Zeile** **05** und **09**, sowie
	- $c_4$ der **Aufwand** für die **Ausführung** von Zeile **06**.
- Dann folgt für die worst-case Komplexität:
$$
\begin{align}
T_{wc}(n) &= c_1 + c_2 · n + c_3 · (n-1) + c_4 · (n-1) \\
&= (c_2+c_3+c_4) · n + c_1 - c_3 - c_4
\end{align}
$$
- Für die **Berechnung** der **average-case Komplexität**, ist die **Frage**, **wie** **oft** **Zeile** **06** **ausgeführt** **wird**.
- Sei $n_m$ die **mittlere** **Anzahl** der **Ausführung** von **Zeile** **06**. Dann folgt:
$$
\begin{align}
T_{ac}(n) = c_1 + c_2 · n + c_3 ·(n+1) + c_4 · n_m
\end{align}
$$
- Als **Eingabe** **betrachten** wir als **Spezialfall** eine **Permutation** der **Zahlen** **1 bis n**.
- Es gilt $n!$ **Permutationen**.
- **Frage**: wie groß ist die **Anzahl** der **Folgen** **mit** $a[2] > a[1]$?
$$
\begin{align}
\begin{array}{cc}
123 & 231 \\ 132 & 312 \\ 213 & 321
\end{array}
\ \Rightarrow \frac{1}{2}n! \ solche \ Permutationen
\end{align}
$$
- **nächste** **Frage**: **wie** **groß** ist die **Anzahl** der **Permutationen** mit $a[3] > a[1] \wedge a[3] > a[2]$?
	- In dem Fall $\frac{1}{3} n!$ **Permutationen**.
$\vdots$
- **Wann** bgilt $a[n] > a[1]$ **und** $a[n] > a[2]$ **und** $\ldots a[n] > a[n-1]$?
- **Antwort**: in $\frac{1}{n} · n! = (n-1)!$ aller **Permutationen**
- Daraus folgt:
$$
n_m = \frac{\frac{1}{2}n! + \frac{1}{3}n! + \ldots + \frac{1}{n}n!}{n!} = \sum^{n}_{k=2} ≈ \ln(n)
$$
- und damit:
$$
T_{ac}(n) ≈ c_1 - c_3 + (c_2 + c_3) · n + c_4 · \ln(n)
$$