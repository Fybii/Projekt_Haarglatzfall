- Der **Name Const** sagt dem **Compiler, das jenes benannte Objekt nicht modifiziert werden darf (read only)**

## Beispiele

### Berechnung des Umfangs eines Kreises

```c++

#include <iostream>

int main() {
//mit const versehende Objekte werden meinst groß geschrieben
const double PI = 3.14159;
//const verhindert diesen Schritt, bzw. zeigt ihn als Fehler an
PI 420.69
double radius = 10;
double = circumference = 2 * pi * radius;

std::cout << circumference << "cm";

return 0;
}

//Output:
62.8318cm

//Weitere Beispiele
const int LIGHT_SPEED = 299792458;
const int WIDTH = 1920;
const int HEIGHT = 1080;
```

## Const-Parameters
- **Const-Parameter** sind modifizierte Parameter mit dem **Const-Operator** (read only)
- **Der Code ist sicherer** und es ist brauchbar beim arbeiten mit **Referenzen und Pointern**

```c++
void printInfo(const std::string &name, const int &age);

int main() {
	
	std::string name = "Bro";
	int age = 21;
	
	printInfo(name, age);
	
	return 0;
}
void printInfo(const std::string &name, const int &age) {
	name = "";
	age = 0;
	std::cout << name << "\n";
	std::cout << age << "\n";
}
//Output:
Error age name
```