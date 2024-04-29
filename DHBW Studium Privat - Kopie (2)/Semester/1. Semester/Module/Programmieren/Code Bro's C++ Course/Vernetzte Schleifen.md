```c++

for (int i = 1; i <= 3; i++) {

	for(int j = 1; j <= 10; j++) {
		std:: cout << j << ' ';
		
	}
	std::cout << '\n';
}
//Output
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
```

```c++
//Rechteck generieren
int rows;
int columns;
int symbol;

std::cout << "How many rows?: ";
std::cin >> rows;

std::cout << "How many columns?: ";
std::cin >> columns;

std::cout << "Enter a symbol to use: ";
std::cin >> symbol;

for (int i = 1; i <= rows; i++) {

	for(int j = 1; j <= columns; j++) {
		std:: cout << symbol;
		
	}
	std::cout << '\n';
}

//Output:
How many rows?: 5
How many columns?: 3
Enter a symbol to use: @
@@@@@
@@@@@
@@@@@
```