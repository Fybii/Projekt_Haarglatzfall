- Wir sind **nicht** **an** der **genauen** **Komplexität** **interessiert**, **sondern** **nur** wie sich diese **qualitativ** für **große** **n** **verhält**.

### Beispiel:
- Die **Komplexität** geht **quadratisch** in $n$. Dazu **gibt** **es** einen **Formalismus**

---
- Im folgenden betrachten wir **Funktionen** der **Form** $f: \mathbb{N} \rightarrow \mathbb{R_+}$ mit $\mathbb{R_+} = \{x \in \mathbb{R} \mid x \leq 0\}$ 

## O-Notation
- Mit $O(f)$ **bezeichnen** wir eine **Klasse** von **Funktionen** $g$ mit der **Eigenschaft**:
$$
\exists c \in \mathbb{R_+} \ \exists n_0 \in \mathbb{N} \ \forall n > n_0 : g(n) \leq c · f(n)
$$
![[Pasted image 20240410195215.png]]

## $\ohm$-Notation
- Mit $\ohm(f)$ **bezeichnen** wir die **Klasse** von **Funktionen** $g$ mit der **Eigenschaft**:
$$
\exists c \in \mathbb{R_+} \ \exists n_0 \in \mathbb{N} \ \forall n > n_0 : g(n) \geq f(n)
$$

## Θ-Notation
- Mit $Θ(f)$ **bezeichnen** wir die **Klasse**:
$$
Θ(f) = O(f) \wedge \ohm(f)
$$
- z.B.
	- $g(n) = n \in O(n^2)$
	- $g(n) = 2n^2 + 5 \in \ohm(n)$
	- $g(n) = 100^2 + 5 \in Θ(n^2)$
	
	![[Pasted image 20240410195543.png]]

## Beispiele

1. Es gilt: $3n^4 + 7n^3 - 2 · ln (n+1) \in O(n^4)$
	- Für alle $n \in \mathbb{N}$ gilt $3n^4 + 7n^3 - 2 · ln (n+1) \leq 3n^4 + 7n^3$
	- Für alle $n \geq 1$ folgt: $1 \leq n \mid · \ n^3 \Rightarrow n^3 \leq n^4$
	- Da auch $0^3 = 0 \leq 0^4 = 0$ gilt, folgt $n^3 \leq n^4$ für alle $\mathbb{N}$
	- $\Rightarrow (g(n)) \ 3n^4 + 7n^3  2 · ln(n+1) \leq (f(n)) \ 3 n^4 + 7n^4 = 10n^4$ 
	- Mit $n_0$ und $c=10$ folgt $g(n) \leq c · n^4$ für alle $n \geq n_0$