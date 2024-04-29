
## abs()

- Steht für "**absolute value**" und steht für den **Betrag**, also $|x|$. benötigt `#incude <cmath>`

```c++
#include <cmath>

double x = -9;
double z;

z = abs(x);
std::cout << z;
//Output:
9

```

## append()

- **Add** a **String** to **another**

```c++
std::string name;

std::cout << "Enter your name: ";
std::getline(std::cin, name);

name.appen("@gmail.com");

std::cout << "Your username is now " << name;
//Output:
Enter your name: Gleggmire
Your username is now Gleggmire@gmail.com
```

## at()

- **Ausgeben** eines **Characters** an einer **bestimmten Position**

```c++
std::string name;

std::cout << "Enter your name: ";
std::getline(std::cin, name);

std::cout << name.at(0);
std::cout << name.at(1);
std::cout << name.at(2);
std::cout << name.at(3);
//Output:
Enter your name: Gelg
G
e
l
g
```

## ceil()

- **Rundet** seinen **Eingabeparameter immer auf**. Benötigt `#inlcude <cmath>`

```c++
#include <cmath>

double x = 3.14;
double y = 3.67;
double ceilx;
double ceily;

ceilx = ceil(x);
ceily = ceil(y);

std::cout << ceilx << std::endl;
std::cout << ceily;
//Output:
4
4
```

## clear()

- löscht den **String**.

```c++
std::string name;

std::cout << "Enter your name: ";
std::getline(std::cin, name);

name.clear();

std::cout << "Hello " << name;
//Output:
Enter your name: Bro
Hello 
```
## empty()

- Wird nur **true**, wenn der **String leer** ist.

```c++
std::string name;

std::cout << "Enter your name: ";
std::getline(std::cin, name);

if(name.empty()) {
	std::cout << "You didn't enter a name";
}
else {
	std::cout << "Hello" << name;
}

//Output:
''
You didn`t enter a name

Enter your name: Bro
Hello Bro
```

## erase()

- Ein **bestimmtes Intervall** in einem **String löschen**

```c++
std::string name;

std::cout << "Enter your name: ";
std::getline(std::cin, name);

name.erase(0, 5);

std::cout << name;
//Output
Enter your name: Gleggmire
mire
```

## find()

- **Finde** einen bestimmten **Character** in einem **String**

```c++
std::string name;

std::cout << "Enter your name: ";
std::getline(std::cin, name);

std::cout << name.find(' ');
//Output:
Enter your name: Total verschmieren
5
```

## floor()

- **Rundet** seinen **Eingabeparameter immer ab**. Benötigt `#inlcude <cmath>`

```c++
#include <cmath>

double x = 3.14;
double y = 3.67;
double floorx;
double floory;

floorx = floor(x);
floory = floor(y);

std::cout << floorx << std::endl;
std::cout << floory;
//Output:
4
4
```

## insert()

- **Setzen** eins **Characters** an bestimmter stellen

```c++
std::string name;

std::cout << "Enter your name: ";
std::getline(std::cin, name);

name.insert(0, "@")

std::cout << name;
//Output:
Enter your name: Gelg
@Gelg
```

## length()

- Gibt die **Länge** eines **Strings** aus

```c++
std::string name;

std::cout << "Enter your name: ";
std::getline(std::cin, name);

if(name.length() > 12) {
std::cout << "Your name can't be over 12 characters long";
}

else {
	std::cout << "Welcome" << name;
}

return 0;
//Output:
Enter your name
Gege Anderson
Welcome

Enter your name
HDSODSDCMDMCDSMMCSCMS
Your name can`t be over 12 characters long
```


## round()

- **Rundet** seinen **Eingabeparameter** nach **mathematischen Regeln** auf oder ab. Benötigt `#inlcude <cmath>`

```c++
#include <cmath>

double x = 3.14;
double y = 3.67;
double roundx;
double roundy;

roundx = round(x);
roundy = round(y);

std::cout << roundx << std::endl;
std::cout << roundy;
//Output:
3
4
```

## std::cin.clear()
- Löscht **Input flags**, um abstürzen des **Systems durch Eingabe eines falschen Datentyps zu vermeiden**.
- Am besten zu kombinieren mit `fflush(stdin)`
```c++
std::cin.clear();
fflush(stdin);
```

## std::getline()

- Wird verwendet um z.B. eine **Eingabe** eines **Strings** mit **Leerzeichen** zu ermöglichen.
```c++

std::cout << "What's your full name?: ";
std::getline(std::cin >> std::ws, name)

std::cout << "Hello " << name '\n';

//Output:
What`s your full name?: 'Max Pen'
Hello 'Max Pen';

```

## std::max()

- Wird verwendet um die **höchste Zahl**, also das **Maximum**, aus seinen **Eingabeparametern** zu ermitteln.

```c++
double x = 3;
double y = 4;
double z;

z = std::max(x, y);
std::cout << z;
//Output:
4
```

## std::min()

- Wird verwendet um die **niedrigste Zahl**, also das **Minimum**, aus seinen **Eingabeparametern** zu ermitteln.

```c++
double x = 3;
double y = 4;
double z;

z = std::min(x, y);
std::cout << z;
//Output:
3
```


## sqrt()

- Wird verwendet, um die **Wurzel** seines **Eingabeparameters** zu bestimmen. benötigt `#include <math>`

```c++
#include <cmath>

double x = 9;
double z;

z = sqrt(x);
std::cout << z;
//Output:
3
```

## pow()

- Wird verwendet um **Potenzrechnungen** durchzuführen, benötigt `#include <cmath>`, dabei ist der **erste Eingabeparameter** die **Basis**, der **zweite** die **Potenz**

```c++
#include <cmath>

double x = 3;
double y = 4;
double z;

z = pow(x, y);
std::cout << z;
//Output:
81
```