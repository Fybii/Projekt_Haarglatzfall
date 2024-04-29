- **Structs** sind **Strukturen** welche **Gruppenzugehörige** **Variablen** unter einen **Namen bringen**.
- **Structs** können verschiedene **Daten** von verschieden **Datentypen** tragen.
- Auf **Member** kann über den **Class Member Access Operator** (.) zugegriffen werden.

```c++

struct student {
	std::string name;
	double gpa;
	bool enrolled = true;
};

int main() {

student student1;
student1.name = "Spongebob";
student1.gpa = 3.2;
student1.enrolled = true;

student student2
student2.name = "Spongebob";
student2.gpa = 3.2;

std::cout << student1.name << "\n";
std::cout << student1.gpa << "\n";
std::cout << student1.enrolled << "\n";

std::cout << student2.name << "\n";
std::cout << student2.gpa << "\n";
std::cout << student2.enrolled << "\n";

return 0;
}
//Output:
Spongebob
3.2
true

Spongebob
3.2
1
```

## Structs an Funktionen übergeben

```c++

struct Car{
	std::string model;
	int year;
	std::string color;
};

void printCar(Car car);
void paintCar(Car &car);
int main() {

Car car1;
Car car2;

car1.model = "Mustang";
car1.year = 2023;
car1.color = "red";

car2.model = "Corvette";
car2.year = 2024;
car2.color = "blue";

paintCar(car1, "silver");
paintCar(car2, "gold")

std::cout << &car1 << "\n";
printCar(car1);
printCar(car2);

return 0;
}

void printCar(Car car) {
	std::cout << &car << "\n";
	std::cout << car.model << "\n";
	std::cout << car.year << "\n";
	std::cout << car.color << "\n";
}

void paintCar(Car &car, std::string color) {
	car.color = color;
}

//Output:
//Verschiedene Adressen
(Adresse1)
(Adresse2)
Mustang
2023
silver

Corvette
2024
gold
//Mit &-Operator (gleiche Adressen)
```