 - Der $?$ **Operator** ist ein andere **Schreibweise** einer **If-Anweisung**

## Beispiel
```c++
int grade = 75;

grade >= 60 ? std::cout << "you pass!" : std::cout << "You fail!";

//Output:
you pass!
//Für grade < 60
you fail!

int number = 9;
int secondNumber

number % 2 == 1 ? std::cout << "ODD" : std::count << "EVEN"; 
number % 2 ? std::cout << "ODD" : std::count << "EVEN"; 
secondnumber % 2 == 1 ? std::cout << "ODD" : std::count << "EVEN"; 
secondnumber % 2 ? std::cout << "ODD" : std::count << "EVEN"; 

//Output:
ODD
ODD
EVEN
EVEN

bool hungry = true;

hungry == true ? std::cout << "You are hungry" : std::cout << "You are full"
hungry ? std::cout << "You are hungry" : std::cout << "You are full"

//Output:
You are hungry
```