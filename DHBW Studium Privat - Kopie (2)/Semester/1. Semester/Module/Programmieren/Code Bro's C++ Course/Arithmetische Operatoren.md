- **Arithmetische Operatoren** werden verwendet um das **Ergebnis** einer **arithmetischen Operation** auszugeben. Dazu gehören ($+\mid -\mid / \mid *$).

## Beispiel
```c++
#include <iostream>

int main() {

	int students = 20;
	
	//Addition:
	students = students + 1;
	//oder
	students += 1;
	//wenn 1 addiert wird
	students++;
	
	std::cout << students;
	//Output:
	21

	//Subtraktion
	students = students - 1;
	//oder
	students -= 1;
	//wenn 1 subtrahiert wird
	students--;

	std::cout << students;
	//Output:
	19

	//Multiplikation
	students = students * 2;
	//oder
	students *= 2;

	std::cout << students;
	//Output:
	40

	students = students / 2;
	//oder
	students /= 2;

	std::cout << students;
	//Output:
	10
	
	//Beispiel des Restoperators mod:
	int remainder = students % 2;

	std::cout << remainder;
	//Output:
	0

	int remainder = students % 3;

	stud::cout << remainder;
	//Output:
	2
}
```

## Reihenfolge:
- Es gelten die **normalen Mathematischen Regeln**
	1. **Klammern**
	2. **Multiplikation und Division**
	3. **Addition und Subtraktion**

### Beispiel
```c++
int students= 6 - (5 + 4) * 3 / 2

std::cout << students;
//Output:
-7
```