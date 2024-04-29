- Mit einer **For-Schleife**, kann man jedes **Element in einem Array ausgeben, auslesen...**
```c++
std::string students[] = {"Spongebob", "Patrick", "Squidward",
						  "Sandy"}

for(int i = 0; i < sizeof(students)/sizeof(students[0]); i++) {
	std::cout << students[i] << "\n";
}

//Output:
Spongebob
Patrick
Squidward
Sandy
```

## Suche nach einem bestimmten Element in einem Array
```c++
int searchArray(int array[], int size, int element);

int main () {
	int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	int size = sizeof(numbers)/sizeof(numbers[0]);
	int index;
	int myNum;
	
	std::cout << "Enter element to search for: " << "\n";
	std::cin >> myNum;
	
	index = searchArray(numbers, size, myNum);
	
	if (index != -1) {
		std::cout << myNum << " is at index " << index;
	}
	else {
		std::cout << myNum << " is not in the array \n";
	}
}

int searchArray(int array[], int size, int element) {
	for (int i = 0; i < size; i++) {
		if(array[i] == element) {
			retunr i;	
		}
		else {
		return -1
		}
	}
}

//Output:
Enter element to search for: 5
5 is at index 4

```

## Sortieren eines Arrays mit Bubble sort
```c++
void sort(int array [], int size);

int main ()
{
	int array[] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
	int size = sizeof(array)/sizeof(array[0]);

	sort(array);
	
	for (int element : array) {
		std::cout << element << " ";
	}
	
	return 0;
}

void sort(int array [], int size) {
	int temp;
	for(int i = 0; i < size - 1; i++) {
		for(int j; i < size - i - 1; j++) {
			if(array [j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
};

//Output:
1 2 3 4 5 6 7 8 9 10
```

## Auffüllen eines Arrays mit User Input
```c++
int main() {

	std::string foods[5];
	int size = szeof(foods)/sizeof(foods[0]);
	std::string temp;
	
	for(int i = 0; i < size, i++) {
		std::cout << "Enter a food you like or q to quit #" 
				  << i + 1 << ": ";
		std::getline(std::cin, temp)
		if(temp == "q") {
			break;
		}
		else {
			foods[i] = temp;
		}
	}
	
	std::cout << "You like the following food\n";
	
	for(int i = 0; !foods[i].empty(); i++) {
		std::cout << foods[i] << "\n";
	}
	
	return 0;
}
//Output:
Enter a food you like #1: pizza
Enter a food you like #2: hamburger
Enter a food you like #3: cheese
Enter a food you like #4: meat
Enter a food you like #5: fish
You like the following food:
pizza
hamburger
cheese
meat
fish

//Output:
Enter a food you like #1: pizza
Enter a food you like #2: hamburger
Enter a food you like #3: cheese
You like the following food:
pizza
hamburger
cheese
```