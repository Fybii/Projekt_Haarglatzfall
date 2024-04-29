- Bei **Type conversion** spricht man vom **Konvertieren** der **value** eines **Datentypes** zu einen anderen.
	- **Implizit: automatisch**
	- **Explizit:  Verleihen eines Datentypes für die Variable, welche dann in einem anderen Datentyp gespeichert wird**.

## Beispiel Implizit:
```c++
int x = 3.14;

std::cout << x;
//Output:
3
```
- In diesem Fall wurde **automatisch** die **Value** von $x$, also $3.14$ mit Hilfe der **Type conversion** zu einer **ganzen Zahl**, (Integer) **konvertiert**.

## Beispiel Explizit
```c++

(int) x //explizit
double x = (int) 3.14

std::cout << x;
//Output:
3

////////////////////

int correct 8;
int questions 10;
double score = correct/(double)questions * 100;

std::cout << score << "%";

```