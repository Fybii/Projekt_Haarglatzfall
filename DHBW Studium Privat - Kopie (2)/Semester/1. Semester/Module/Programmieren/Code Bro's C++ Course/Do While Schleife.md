- Bearbeitet zuerst einen **Codeblock** und **prüft danach** die **Condition**.

```c++
int number;
//wird nicht ausgeführt
while(number < 0) {
	std::cout << "Enter a positive #: ";
	std::cin >> number;
}

std::cout << "The # is: " << number;
//Output:
The # is: 0
```

```c++
int number;
//wird mindestens einmal ausgeführt
do {
	std::cout << "Enter a positive #: ";
	std::cin >> number;
}while(number < 0)

std::cout << "The # is: " << number;
//Output:
Enter a positive #: -1
Enter a positive #: 4
The # is: 4
```