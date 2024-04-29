- Eine **Datenstruktur**, welche mehrere **Werte** in sich tragen kann, dabei hat jeder **Wert eine dazugehörige Index Nummer**.

- **Arrays** können nur den selben **Datentyp** in sich tragen. 

- **Arrays können auch nachher assigned werden**.


```c++

std::string cars[] = {"Corvette", "Mustang", "Camry"};

std::cout << cars[0];
std::cout << cars[1];
std::cout << cars[2];

//oder

std::string cars[3];

cars[0] = "Corvette";
cars[1] = "Mustang";
cars[2] = "Camry";

std::cout << cars[0];
std::cout << cars[1];
std::cout << cars[2];
//Output:
Corvette
Mustang
Camry
```

## Multidimensional Arrays
- **2D**
```c++
int main() {

std::string cars[][3] = {{"Mustang", "Escape", "F-150"},
						{"Corvette", "Equinox", "Silverado"},
						{"Challenger", "Durango", "Ram 1500"}};

std::cout << cars[0][0] << " ";
std::cout << cars[0][1] << " ";
std::cout << cars[0][2] << "\n";
std::cout << cars[1][0] << " ";
std::cout << cars[1][1] << " ";
std::cout << cars[1][2] << "\n";
std::cout << cars[2][0] << " ";
std::cout << cars[2][1] << " ";
std::cout << cars[2][2] << " ";
return 0
}

//Output:
Mustang Escape F-150
Corvette Equinox Silverado 
Challenger Durango Ram 1500

```
```c++
```c++
int main() {

std::string cars[][3] = {{"Mustang", "Escape", "F-150"},
						{"Corvette", "Equinox", "Silverado"},
						{"Challenger", "Durango", "Ram 1500"}};

int rows = sizeof(cars)/sizeof(cars[0]);
int columns = sizeof(cars[0])/sizeof(cars[0][0]);

for (int i = 0; i < rows; i++) {
	for(int j; j < columns; j++) {
		std::cout << cars[i][j] << " ";
	}
	std::cout << "\n";
}
return 0
}
//Output:
Mustang Escape F-150
Corvette Equinox Silverado 
Challenger Durango Ram 1500
```