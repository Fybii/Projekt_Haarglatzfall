- **Rekursion** bedeutet, dass eine **Funktion** sich selbst in sich **aufruft**.
- **Vorteil:** weniger Code und übersichtlicher
- **Nachteil**: benötigt mehr Speicher und ist langsamer
```c++
void walk(int steps);
void recursiveWalk(int steps);

int main() {

	walk(100)

return 0
}

void walk(int steps) {
	for (int i = 0; < steps, i++) {
		std::cout << "You take a step"
	}
}

void recursiveWalk(int steps) {
	if(steps > 0) {
		std::cout << "You take a step\n";
		recursiveWalk(steps - 1);
	}
}
//Output:
(Selbes Ergebnis)
```

```c++
int facrorial (int num);
int recursiveFactorial(int num);
int main() {

std::cout << factorial(10);
std::cout << recursiveFactorial(10);

return 0;
}

int factorial(int num) {
	int result = 1;
	for(int i = 0; i <= num; i++) {
		result = result * i;
	}
	return result;
}

int recursiveFactorial(int num) {
	if(num > 1) {
		return num * factorial(num - 1);
	}
	else {
		return 1;
	}
}

//Output:
(selbe Zahl)
```