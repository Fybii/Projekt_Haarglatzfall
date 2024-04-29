```c++
int main() {
	std::string x = "Kool-Aid";
	std::string y = "Water";
	std::string temp;
	
	temp = x;
	x = y;
	y = temp;
	
	std::cout << "X: " << x << "\n";
	std::cout << "Y: " << y << "\n";
	
	return 0;
}

//Output:
X: Water
Y: Kool-Aid
```

## Pass by value
- Erstellen einer **Kopie** einer **Variable**, welche **Funktionen übergeben wird**.
- $\rightarrow$ **Vier Speicheradressen** für $x$ und $y$ jeweils **zwei**
```c++
void swap(std::string x, std::string y);

int main() {
	std::string x = "Kool-Aid";
	std::string y = "Water";
	
	swap(x, y);
	
	std::cout << "X: " << x << "\n";
	std::cout << "Y: " << y << "\n";
	
	return 0;
}
void swap(std::string x, std::string y) {
	
	std::string temp;
	temp = x;
	x = y;
	y = temp;
}

//Output:
X: Kool-Aid
Y: Water
```

## Pass by reference
- **Übergeben** der **Speicheradresse** an eine **Funktion**
- **Zwei Speicheradressen**
```c++
void swap(std::string &x, std::string &y);

int main() {
	std::string x = "Kool-Aid";
	std::string y = "Water";
	
	swap(x, y);
	
	std::cout << "X: " << x << "\n";
	std::cout << "Y: " << y << "\n";
	
	return 0;
}
void swap(std::string &x, std::string &y) {
	
	std::string temp;
	temp = x;
	x = y;
	y = temp;
}

//Output:
X: Water
Y: Kool-Aid
```