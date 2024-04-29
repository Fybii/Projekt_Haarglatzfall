- **Pseudo Random** ist nicht ganz zufällig, aber nahe dran

```c++
#include <ctime>

int main() {

srand(time(NULL));

int num = rand();

std::cout << num;
}

//Output:
3231
```
```c++
int main() {

srand(time(NULL));
//Teilt die Nummer durch 6 und gibt den Rest aus
int num = (rand() % 6 + 1);

std::cout << num;
}
//Output:
Random Nummern zwischen 1 und 6
```