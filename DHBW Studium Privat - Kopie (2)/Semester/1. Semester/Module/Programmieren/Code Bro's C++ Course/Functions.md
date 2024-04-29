```c++
#include...

void happyBirthday(std::string n, int age) {
	std::cout << "Happy Birthday to" << n << "!\n";
	std::cout << "Happy Birthday to" << n <<"!\n";
	std::cout << "Happy Birthday dear "<< n <<"!\n";
	std::cout << "Happy Birthday to" << n << "!\n";
	std::cout << "You are" << age << "Years old!\n";
}

int main() {
	std::string name = "Bro":
	int age = 21
	
	happyBirthday(name);
	
	return 0;
}

//Output:
Happy Birthday to Bro!
Happy Birthday to Bro!
Happy Birthday dear Bro!
Happy Birthday to Bro!
You are 21 Years old!
```

# Overloaded Functions

- **Funktionen** können den **selben Namen** annehmen, doch benötigen sie dann **unterschiedliche Parameter**

```c++
void bakePizza();
void bakePizza(std::string topping1);
void bakePizza(std::string topping1, std::string topping2);

int main() {
	bakePizza();
	bakePizza(Salami);
	bakePizza(Salami, Mushroom);
	return 0;
}

void bakePizza() {
	std::cout << "Here is your pizza!\n";
}

void bakePizza(std::string topping1) {
	std::cout << "Here is your " << topping1 << " pizza\n";
}

void bakePizza(std::string topping1, std::string topping2) {
	std::cout << "Here is your " << topping1 << " and " << 
				 topping2 << " pizza\n";
}

//Output:
Here is your pizza
Here is your Salami pizza
Here is your Salami and mushroom pizza
```

## Übergeben eines Arrays in eine Funktion
```c++

double getTotal(double prices[], int size)

int main() {
	double prices[] = {49.99, 15.05, 75, 9.99};
	int arraySize = sizeof(prices)/sizeof(prices[0]);
	double total = getTotal(prices, size);
	
	std::cout << "$" << total;
	
	return 0;
}

double getTotal(double prices[], int size) {
	double total = 0;
	for (int i; i < size; i++) {
		total += prices[i];
	}
}
//Output:
$150.05
```

- Bei der **Übergabe eines Arrays in eine Funktion**, wird nur der **Speicherpunkt** des **Arrays übergeben**.

## Function Templates

- **Beschreibt den Aufbau einer Funktion**
- Kann benutzt werden, um **so viele überladene Funktion wie benötigt zu generieren**

```c++

template <typename T, typename U>

auto max(T x, U y) {
	return (x > y) ? x : y;
}

int main() {

	std::cout << max(1, 2) << "\n";
	std::cout << max(1.1, 2.2) << "\n";
	std::cout << max('1', '2') << "\n";
	std::cout << max(1, 2.1) << "\n";

return 0;
}
//Output:
2
2.2
2
2.1
```