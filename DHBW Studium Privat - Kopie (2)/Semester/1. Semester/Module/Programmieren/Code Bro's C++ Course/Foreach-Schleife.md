- geht durch jedes **Element in bspweise einem Array**.

```c++
std::string students[] = {"Spongebob", "Patrick", "Squidward"};

for(std::string student : students) {
	std::cout << student << "\n";
}
```

- **Vorteil:** weniger Code
- **Nachteil:** nicht so flexibel