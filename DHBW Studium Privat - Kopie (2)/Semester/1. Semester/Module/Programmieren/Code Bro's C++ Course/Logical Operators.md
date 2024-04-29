## &&
```c++
int temp

std::cout << "Enter the temperature: ";
std::cin >> temp;

//Alle mit UND kombinierten Statements müssen true sein, damit die If Ausage ausgeführt werden kann
if (temp > 0 && temp < 30) {
	std::cout << "The temperature is good!";
}
else {
	std::cout << "The temperature is bad!";
}
//Output:
25
The temperature is good!

45
The temperature is bad!
```

## ||
```c++
int temp

std::cout << "Enter the temperature: ";
std::cin >> temp;

// Mindestens eine der mit ODER verknüpften Aussagen muss true sein, damit die If Aussage ausgeführt wird.
if (temp <= 0 || temp >= 30) {
	std::cout << "The temperature is bad!" << '\n';
}
else {
	std::cout << "The temperature is good!" << '\n';
}
//Output:
25
The temperature is good!

45
The temperature is bad!

-34
The temperature is bad!
```

## !
```c++
bool sunny;

if(!sunny) {
	std::cout << "It is cloudy outside!";
}
else {
std::cout << "It is sunny outside!";
}
```