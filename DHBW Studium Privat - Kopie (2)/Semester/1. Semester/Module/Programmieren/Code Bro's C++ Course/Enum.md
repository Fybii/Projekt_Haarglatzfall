- Ein **Benutzerdefinierter Datentyp**, welcher **Paare** von **integer-Konstanten** beherbergt.
- **Eignen sich sehr** wenn ein bestimmtes **Set** an potenziellen **Optionen besteht**

```c++

enum Day {sunday = 0, monday = 1, thuesday = 2, wednesday = 3, 
		  thursday = 4, friday = 5, saturday = 6}

int main() {
std::string today = sunday;

switch(today) {

	case sunday:
		std::cout << "It is sunday\n";
		break;
	case monday:
		std::cout << "It is monday\n";
		...
		...
		...
		...
}
}
```