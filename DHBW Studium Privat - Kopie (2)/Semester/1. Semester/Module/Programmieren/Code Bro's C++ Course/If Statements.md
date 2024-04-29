- **If-Statements** machen etwas, wenn die **Bedingung** die ihr gegeben wurde, **erfüllt (also ture)** ist.

## Beispiel
```c++
int age;

std::cout << "Enter your age: ";
std::cin << age;

if(age >= 18 && age < 100) {
	std::cout << "Welcome to the site!";
}

else if (age < 0) {
	std::cout << "You haven't been born yet!";
}

else if(age >= 100) {
	std::cout << "Buddy you dead!";
}

else {
	std::cout << "You are to young, bye bye!";
}
//Output:
18
Welcome to the site!

-10
You haven´t been born yet!

120
Buddy you dead!

12
You are to young, bye bye!
```