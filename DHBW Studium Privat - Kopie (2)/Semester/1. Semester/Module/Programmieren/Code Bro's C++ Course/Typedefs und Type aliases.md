# Typedefs

- **Typedefs sind** reservierte **Keywords**, welche benutzt werden um einen **alias** für einen anderen **Datentyp** zu **erstellen**. **Typedefs** ermöglichen neue Identitäten für existierende **Datentypen** und helfen bei der **Lesbarkeit, sowie bei Schreibfehlern**

## Beispiel
```c++

#include <iostream>
#inlcude <vector>

typedef std::vector<std::pair<std::string, int>> pairlist_t

int main() {

	pairlist_t pairlist;
	
	return 0;
}

typedef std::string text_t;
typedef int number_t;
//oder
using text_t = std::string;
using number_t = int;

int main() {

	number_t age = 21;
	text_t firstname = "Bro";

	std::cout << firstname << '\n';
	std::cout << age << '\n';

	return 0;
}

//Output:
Bro
21

```
