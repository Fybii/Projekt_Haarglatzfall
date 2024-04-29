- **Pointer** sind **Variablen**, welche die **Adresse von anderen Variablen** abspeichern, wobei es manchmal einfacher ist mit **Adressen zu arbeiten**
- & = Adresse von Operator
- \* = Dereferenzierung Operator 
```c++
int main() {

	std::string name = "Bro";
	std::string *pName = &name;
	
	std::cout << pname << "\n";
	std::cout << *pname;
	return 0;
}
//Output:
(Adresse)
Bro
```

- Da **Arrays** schon als **Adressen** gespeichert sind, ist kein **&** Operator nötig.

## Null Pointer
- **Null Value** = Eine spezielle **Value**, welche keine **Wertzuweisung**.
- Wenn ein **Pointer** eine **Null Value** hält, bedeutet dass, das der **Pointer** auf nichts **zeigt**.
- `nullptr` **repräsentiert** diesen **null Pointer**
- **Verwendung:** testen, ob eine **Adresse zu einem Pointer zugewiesen wurde**

```c++
int main() {
	int *pointer = nullptr;
	int x = 123;
	
	pointer = &x;
	
	if(pointer == nullptr) {
		std::cout << "address was not assigned\n";
	}
	else {
		std::cout << "address was assigned\n";
		std::cout << *pointer;
	}
	
	return 0;
}
```