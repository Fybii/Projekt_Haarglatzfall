- **Return** gibt einen Wert wieder zurück an seine Funktion

```c++
double square(double length);
double cube(double length);

int main() {

	double length = 5.0;
	double area = square(length);
	double volume = cube(length);
	
	std::cout << "Area: " << area << "cm^2\n";
	std::cout << "Volume " << volume << "cm^3\n";
	
	return 0;
}

double square(double length) {
	double result = length * length;
	return result;
	//oder
	return length * length;
}

double cube(double length) {
	return length * length * length;
}
```

## String Beispiel

```c++

std::string concatStrings(std::string string1, 
						  std::string string 2);

int main() {

	std::string firstName = "Bro";
	std::string lastName = "Code";
	std::string fullName = concatStrings(firstName, lastName);

	std::cout << "Hello" << fullName;
}

std::string concatStrings(std::string string1, 
						  std::string string 2) {
	return string1 + " " + string2;
	}

//Output:
Hello Bro Code
```