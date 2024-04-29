- Eine **Speicheradresse** ist eine **Position im Speicher**, auf der bestimmte **Daten** gespeichert sind.
- Auf eine **Speicheradresse** kann dabei **mithilfe des & (Adresse von Operator) zugegriffen werden**.
```c++
int main() {
	
	std::string name = "Bro";
	int age = 21;
	bool student = true;
	
	std::cout << "&name" << "\n";
	
	return 0;
}
//Output: 
(Adresse des namen in Hexadecimal[0xbd8a1ff600] z.B.)
```

## Dynamischer Speicher

- **Speicher** welcher erst nach dem **kompilieren und starten** zugeordnet wird.
- Dazu wird der **new-Operator** benutzt und es wird **Speicher aus dem Heap, statt aus dem Stack** verwendet.

- **Hilfreich**, wenn wir nicht wissen, wie viel **Speicher** wir benötigen
- Es macht unsere **Programme flexibler**, vor allem beim **benutzen von User Input**

```c++
int main() {

int *pNum = NULL;

pNUm = new int;

*pNum = 21;

std::cout << "address: " << pNum << "\n";
std::cout << "value: " << *pnum << "\n";

delete pNum;

return 0
}
//Output:
(Adresse des Int)
21
```

- Immer nach `new` auch `delete` verwenden.

```c++
int main() {

char *pGrades = NULL;
int size;

std::cout << "How many grades to enter in?: ";
std::cin >> size;

pGrades = new char[size];

for(int i = 0; i < size; i++) {
	std::cout << "Enter grade #" << i + 1 << ": "
	std::cin >> pGrades[i];
}

for(int i = 0; i < size; i++) {
	std::cout << pGrades[i] << "";
}

delete[] pGrades;

return 0;
}

//Output:

How many grades to enter in?: 6
Enter grade #1: A
Enter grade #2: B
Enter grade #3: C
Enter grade #4: D
Enter grade #5: E
Enter grade #6: F
A B C D E F
```