- **Gegeben:** $n$ **Eingabeneuronen** $\underline{x}^1, \underline{x}^2, \ldots, \underline{x}^n$ des $\mathbb{R}^n$

- Weiterhin haben wir **Ausgabeneuronen** $y_i$ die auf einen **2-dimensionalen Gitter** oder auf einer **Linie angeordnet** sind. **Dazu gehören Koordination** $\underline{r}_i$. 

- Die **Eingabeneuronen** sind mit den **Ausgabeneuronen** über **Gewichte** $w_{ij}$ vollständig **verbunden**.

## Frage Bei **Eingabe** $\underline{x} \in \mathbb{R}^n$, **welches Neuron feuert?

- Zu **Ausgabeneuron** $y$: gehört die **$i$-te Zeile von $w_{ij}$.** Dies ist ein **Vektor** $\underline{w}^i$ des $\mathbb{R}^n$.

- **Betrachte** nun die **Abstände** $||\underline{w}^i - \underline{x}||$ und **wähle** das **Neuron** $i^*$ **aus für welchen der Abstand minimal wird**, d.h.
$$
\begin{align}
& ||\underline{w}^{i^*}-\underline{x}|| \leq ||\underline{w}^i-\underline{x}|| & \ für \ alle \ i \\
=> & \sum^{}_{j}(w_{i^*j}-x_i)^2 \leq \sum^{}_{j}(w_{ij}-x_j)^2 & \ für \ alle \ i
\end{align}
$$
$\rightarrow i^*$ ist **feuerndes Neuron**

## Lernregel

$$
\triangle w_{ij} = \eta · f(i,i^*) · (x_j - w_{ij})
$$
- $(x_j - w_{ij}) \rightarrow$ **Gewicht** wird in Richtung der **Eingabe gezogen**

- $f(i,i^*) \rightarrow$ ist die **Nachbarschaftsfunktion**.
$$
f(i,i^*) = e^{-\frac{||\underline{r}_i - \underline{r}_{i^*} || ^2}{2 \sigma}}
$$
$\sigma > 0 \rightarrow$ ist eine **Breite**
$\eta > 0$ ist die **Lernrate**

## Beispiel: Problem des Handlungsreisenden

- Ein **Handlungsreisender** muss $N$ **Städte** besuchen.
- Die **Reihenfolge** der **Besuche** ist **irrelevant**, außer das er am **Ende zur Ausgangsstadt zurückkehrt**.
- Die **Kosten** sind eine **Funktion** der **Weglänge**.
- Es sind die **Kosten zu minimieren**, d.h. eine **möglichst kurze Rundreise**.

### Modellierung
- Die **Städte** sind **Punkte in der Ebene $\mathbb{R}^2$.
- Die **Wegstrecken** sind die **euklidischen Abstände zwischen** den **Punkten**.


### Lösung mit einem kohonen Netz
[Grafik] 

- Es werden **3x mal so viele Neuronen wie Städte** verwendet.
- Jedes **Neuron $i$ hat ein  $\underline{w}_i \in \mathbb{R}$
	- $\Rightarrow$ insgesamt ergibt sich eine **Gewichtsmatrix** $W - \left( \begin{array}{cc} \underline{w}_1 \\ \underline{w}_2 \\  \vdots \\ \underline{w}_n \end{array} \right) = (w_{ij})$ 
- Ermittlung des **Gewichtsneurons $i^*$:**
  $$
  ||\underline{w}^{i^*}-\underline{x}|| \leq ||\underline{w}^i-\underline{x}||  \ für \ alle \ i \\
  $$
#### Lernphase
$$
\begin{align}
\triangle w_{ij} &= \eta · f(i,i^*) · (x_j - w_{ij}) \\
f(i,i^*) &= e^{-\frac{||\underline{r}_i - \underline{r}_{i^*} || ^2}{2 \sigma}}  \geq 0 
\end{align} 
$$
- Mit $\eta > 0$ & $\sigma > 0$
- $||r_i - r_{i^*}||$ ist der **räumliche Abstand** von $i$ zu $i^*$ ***auf dem Kreis***.


