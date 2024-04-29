# Variablen

- **Variablen** sind **Repräsentationen** einer Zahl oder eines Begriffes.

- Dabei unterscheidet man von **zwei Arten** des Zuordnens.
## Beispiel
```c++

//deklaration
int x 
//Benennung an einem späteren Zeitpunkt
x = 5 

//Kombination aus beiden
int x = 5;

```



# Datentypen

- Der **Datentyp** einer **Variable** entscheidet, welche Art von **character** er **speichern** kann

## Beispiel
```c++

//Integer -- (Ganze Zahl): Alter, Jahr, Tage etc...
int x = 5;
int y = 6;
int sum = 0;

std::cout << sum << std::endl;

//Output:
11

//Double -- (Zahl mit Nachkommastellen)
double price = 10.99;
double gpa = 2.5;
double temperature = 25.1;

std::cout << price << std::endl;
std::cout << gpa << std::endl;
std::cout << temperature << std::endl;

//Output:
10.99
2.5
25.1

//Char -- (Einzelner Character)
char grade = 'A';
char initial = 'B';

std::cout << grade << std::endl;
std::cout << initial << std::endl;

//Output:
A
B

//Boolean -- (true or false)
bool student = true;
bool power = false;

std::cout << student << std::endl;
std::cout << power << std::endl;

//Output:
true
false

//String (Objekt, welches eine Sequent eine Textes repräsentiert)
std::string name = "Bro";
std::string day = "Friday";
std::string food = "pizza";
std::string address = "123 Fake Street";

std::cout << name; << endl;
std::cout << day; << endl;
std::cout << food; << endl;
std::cout << address; << endl;

//Output:
Bro
Friday
pizza
123 Fake Street
```

## Ausgabe von Variable und String in einem

```c++

std::string name = "Bro";
int age = 21

std::cout << "Hello " << name << "." '\n';
std::cout << "You are " << age << " years old" << ".";

//Output:
Hello Bro.
You are 21 years old.
```