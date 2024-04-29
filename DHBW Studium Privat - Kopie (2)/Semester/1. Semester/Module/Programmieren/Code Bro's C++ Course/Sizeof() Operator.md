- Gibt die **Größe** einer **beliebigen Datenstruktur** in **Bytes** an.

```c++
double gpa = 2.5;

std::cout << sizeof(gpa) << " bytes\n";

//Output:
8 bytes

std::string name = "Bro";

std::cout << sizeof(name) << " bytes\n";

//Output:
32 bytes

char grade = 'F';

std::cout << sizeof(grade) << " bytes";

//Output:
1 bytes

bool student = true;

std::cout << sizeof(student) << " bytes";
```

## Arrays
```c++
char grades[] = {'A', 'B', 'C', 'D', 'F'};

std::cout << sizeof(grades) << " bytes\n";
std::cout << sizeof(grades/sizeof(grades[0]) << " elements\n";

//Output:
5 bytes
5 elements
```