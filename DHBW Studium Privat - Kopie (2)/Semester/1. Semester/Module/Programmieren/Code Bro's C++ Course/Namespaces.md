- Werden benutzt um **Namenskonflikte** in **Projekten** zu vermeiden. Normalerweise benötigt **jedes entity** einen **einzigartigen Namen**. Durch **Namespaces**, können aber auch **identisch genannte entitys** erzeugt werden, sollten die **Namespaces unterschiedlich sein**


## Beispiel

```c++

#inlcude <iostream>

namespace first{
	int x = 1
}
namespace second{
	int x = 2;
}

int main () {

	int x = 0;
	
	std::cout << x << endl;
	std::cout << first::x << endl;
	std::cout << second::x << endl;
	
}

//Output:

0
1
2

```

# using Namespace

- Wenn **using Namespace** im **Main** angegeben wird, so werden die im **Namespace** angegebenen Objekte oder Variablen verwendet.

## Beispiel

```c++

#inlcude <iostream>

namespace first{
	int x = 1
}
namespace second{
	int x = 2;
}

int main () {
	using namespace first;
	
	std::cout << x << std::endl;
	
}

//Output:
1
```

```c++
#inlcude <iostream>

//std ist nicht mehr nötig
using namespace std;

int main () {

	cout << "Hello World" << endl;
	
}

//Output:
Hello World
```