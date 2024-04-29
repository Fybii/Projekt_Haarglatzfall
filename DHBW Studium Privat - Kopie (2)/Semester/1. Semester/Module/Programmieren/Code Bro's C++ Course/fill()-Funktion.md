- Fühlt eine **beliebige Anzahl eines bestimmten Elements** in einem **ausgesuchten Definitionsbereich**

```c++
int main (){

	const int SIZE = 100;

	std::string foods[SIZE];
	fill(foods, foods + SIZE/2, "pizza");
	fill(foods + SIZE/2, foods + SIZE, "Hamburger");

	for(std::string food : foods) {
		std::cout << food << "\n";
	}

	return 0;
}

//Output:
pizza
pizza
pizza
...
...
...
(size/2 mal)
Hamburger
Hamburger
Hamburger
...
...
...
(size/2mal)
```