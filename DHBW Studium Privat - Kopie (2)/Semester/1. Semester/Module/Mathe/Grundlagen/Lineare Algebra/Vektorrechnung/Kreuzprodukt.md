![[Pasted image 20240221194746.png]]

**=> Kreuzprodukt**
- Seien $\vec{a}, \vec{b} \in \mathbb{R}^3$. Es ist $\vec{c} = \vec{a} \times \vec{b}$, wenn:
	1. $\vec{c} \perp \vec{a} \wedge \vec{c} \perp \vec{b}$ 
	2. $|\vec{a} \times \vec{b}| = |\vec{a}| · |\vec{b}| · \sin \varphi_{\vec{a} \vec{b}}$
	3. $\vec{a}, \vec{b}, \vec{c} \ bilden \ RHS$

#### Beispiel
$$
\begin{align}
\left( 
\begin{array}{cc}
3 \\ 4 \\ 5
\end{array}
\right)
\times
\left(
\begin{array}{cc}
-5 \\ 0 \\ 3
\end{array}
\right) = 
\left(
\begin{array}{cc}
4·3-0·5 \\ 5 · (-5) - 3·3 \\ 3·0 - (-5)·4
\end{array}
\right)
\end{align}
$$

$$
\begin{align}
\left( 
\begin{array}{cc}
3 \\ 4 \\ 5
\end{array}
\right)
\times
\left(
\begin{array}{cc}
-5 \\ 0 \\ 3
\end{array}
\right) &= 
\begin{vmatrix}
\vec{e}_x & \vec{e}_y & \vec{e}_z \\
3 & 4 & 5 \\
-5 & 0 & 3
\end{vmatrix} \\
&=
\begin{array}{cc}
\vec{e}_x · 4 · 3 - \vec{e}_x · 5 · 0 \\
\vec{e}_y · 5 · (-5) - \vec{e}_y · 3 · 3 \\
\vec{e}_z · 3·0 - \vec{z} · 4 · (-5)
\end{array} \\
&=
\left(
\begin{array}{cc}
12 \\ -34 \\ 20
\end{array}
\right)
\begin{array}{cc}
\vec{e}_x \\
\vec{e}_y \\
\vec{e}_z
\end{array}
\end{align}
$$

## Anwendungen

### Flächeninhalt
![[Pasted image 20240221200323.png]]

$$
\begin{align}
A_\square &= |\vec{a} \times \vec{b}| \\
A_\triangle &= \frac{1}{2}|\vec{a} \times \vec{b}|
\end{align}
$$

### Spatprodukt
![[Pasted image 20240221200610.png]]

$$
V = \vec{a} · (\vec{b} \times \vec{c}) = \vec{b} · (\vec{c} \times \vec{a}) = \vec{c} · (\vec{a} \times \vec{b})
$$