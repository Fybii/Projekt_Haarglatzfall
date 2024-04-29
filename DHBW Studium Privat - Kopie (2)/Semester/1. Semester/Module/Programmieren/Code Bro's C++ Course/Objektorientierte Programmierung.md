## Objekt
- **Objekte** sind eine **Kollektion** von **Attributen (Charakteristiken) und Methoden (Aktionen)**
- **können benutzte werden** um **Objekte** des **echten Lebens** darzustellen
- Sie werden **über Klassen erstellt**, welche als **Blue Print** dienen.

```c++
//Klasse des Objekts
class Human {
	public:
		std::string name;
		std::string occupation;
		int age;
		
		void eat() {
			std::cout << "He is eating\n";
		}
		void drink() {
			std::cout << "He drink\n";
		}
		void sleep() {
			std::cout << "He sleep\n";
		}
};

int main() {
	//Objekt
	Human human1;
	
	human1.name = "Rick";
	human1.occupation = "scientist";
	human1.age = 70;
	
	std::cout << human1.name << "\n";
	std::cout << human1.occupation << "\n";
	std::cout << human1.age << "\n";
	
	human1.eat();
	human1.drink();
	human1.sleep();
	
	return 0;
}
//Output:
Rick
scientist
70

He is eating
He drink
He sleep

////////////////////////////////////////////////////////////////////

class Human {
	public:
		std::string name = "Rick";
		std::string occupation = "scientist";
		int age = 70;
		
		void eat() {
			std::cout << "He is eating\n";
		}
		void drink() {
			std::cout << "He drink\n";
		}
		void sleep() {
			std::cout << "He sleep\n";
		}
};

int main() {
	//Objekt
	Human human1;
	
	std::cout << human1.name << "\n";
	std::cout << human1.occupation << "\n";
	std::cout << human1.age << "\n";
	
	return 0;
}
//Output:
Rick
scientist
70
```

## Constructor
- Eine **spezielle Methode**, welche **ausgeführt** wird, sobald ein **Objekt** instantziert wird.
- **Hilfreich**, um **Attributen**, **Values** als **Argument** zu übergeben.

```c++

class Student{
	public:
		std::string name;
		int age;
		double gpa;
		
	Student(std::string name, int age, double gpa) {
		this->name = name;
		this->age = age;
		this->gpa = gpa;
		
	}

};

int main() {

	Student student1("Spongebob", 25, 3.2);
	Student student2("Patrick", 40, 1.5);
	Student student3("Sandy", 21, 4.0);
	
	std::cout << student1.name << "\n";
	std::cout << student1.age << "\n";
	std::cout << student1.gpa << "\n";
	
	std::cout << student2.name << "\n";
	std::cout << student2.age << "\n";
	std::cout << student2.gpa << "\n";

	std::cout << student3.name << "\n";
	std::cout << student3.age << "\n";
	std::cout << student3.gpa << "\n";
	
return 0;
}
//Output:
Spongebob
25
3.2

Patrick
40
1.5

Sandy
21
4.0
```
- **oder**
```c++

class Student{
	public:
		std::string name;
		int age;
		double gpa;
		
	Student(std::string x, int y, double z) {
		name = x;
		age = y;
		gpa = z;
		
	}

};

int main() {

	Student student1("Spongebob", 25, 3.2);
	Student student2("Patrick", 40, 1.5);
	Student student3("Sandy", 21, 4.0);
	
	std::cout << student1.name << "\n";
	std::cout << student1.age << "\n";
	std::cout << student1.gpa << "\n";
	
	std::cout << student2.name << "\n";
	std::cout << student2.age << "\n";
	std::cout << student2.gpa << "\n";

	std::cout << student3.name << "\n";
	std::cout << student3.age << "\n";
	std::cout << student3.gpa << "\n";
	
return 0;
}
//Output:
Spongebob
25
3.2

Patrick
40
1.5

Sandy
21
4.0
```

## Overloaded Constructor
- **Mehrere** **Kontruktoren** mit dem selben **Namen**, aber verschiedenen **Parametern**
- Erlaubt es mit den **Argumenten** zu variieren, wenn ein **Objekt** instantziert wird.

```c++

class Pizza {
	public:
		std::string topping1;
		std::string topping2;


	Pizza() {
	
	};
	Pizza(std::string topping1) {
		this->topping1 = topping1;
	}
		Pizza(std::string topping1, std::string topping 2) {
		this->topping1 = topping1;
		this->topping2 = topping2;
	}
}

int main() {

	Pizza pizza1("pepperoni");
	Pizza pizza2("mushrooms", "peppers");
	Pizza pizza3

	std::cout << pizza1.topping1 << "\n;
	std::cout << piiza2.topping2 << "\n";
	return 0;
}
```

## Getters and Setters
- **Abstraction**: Das **Verstecken** von **unnötigen** **Daten** außerhalb einer **Klasse**
- **Getter**: **Funktion**, welche ein **Privates Attribut** **lesbar** macht
- **Setter**: **Funktion**, welche ein **Privates Attribut** **schreibbar** macht
##### Normal
```c++

class Stove{
	public:
		int temperature = 0;
		
};

int main() {
	
	Stove stove;
	
	stove.temperature = 1000000000;
	
	std::cout << "The Temperature is: " << stove.temperature << "\n";
	
	return 0;
}
//Output:

The Temperature is: 10000000000
```

##### Abstraction
```c++
class Stove{
	private:
		int temperature = 0;
		
};

int main() {
	
	Stove stove;
	
	stove.temperature = 1000000000;
	
	std::cout << "The Temperature is: " << stove.temperature << "\n";
	
	return 0;
}
//Output:
err
```

##### Getter
```c++
class Stove{
	private:
		int temperature = 0;
		
	public:
	int getTemperature() {
		return temperature;
	}
		
};

int main() {
	
	Stove stove;
	
	//stove.temperature = 1000000000; Nicht möglich, da nur lesbar
	
	std::cout << "The Temperature is: " << stove.getTemperature 
										<< "\n";
	
	return 0;
}
//Output:
The Temperature is: 0
```

##### Setter
```c++
lass Stove{
	private:
		int temperature = 0;
		
	public:
	Stove(int temperature) {
		setTemperature(temperature);
	}
	int getTemperature() {
		return temperature;
	}
	void setTemperature(int temperature) {
		if(temperature < 0) {
			this->temperature = 0;
		}
		else if (temperature >= 10) {
			this->temperature = 10;
		}
		else {
			this->temperature = temperature;
		}
	}
		
};

int main() {
	
	Stove stove(0);
	
	stove.setTemperature(1000000); // jetzt schreibbar#
	stove.setTemperature(-100);
	
	std::cout << "The Temperature is: " << stove.getTemperature 
										<< "\n";
	
	return 0;
}
//Output:
0
10
0
```

## Verheiratung 
- Man spricht dabei von der **Möglichkeit**, dass eine **Klasse** **Attribute** und **Methoden** von anderen **Klassen** erben können.
- Dabei spricht man von **parent class** und **children class**, wobei **children von parents erben**
- **Hilft**, bei der **Wiederverwendung** gleicher **Codeschnipsel**
```c++

class Animal {
	public:
		bool alive = true;

	void eat() {
		std::cout << "Animal is eating\n";
	}
};

class Dog : public Animal {
	public:

	void bark() {
		std::cout << "The dog goes woof!\n";
	}
};

class Cat : public Animal {
	public:

	void meow() {
		std::cout << "The cat goes meow\n";
	}
	
}

int main() {

	Dog dog;
	Cat cat;

	std::cout << dog.alive << "\n";
	dog.eat();
	dog.bark();

	std::cout << cat.alive << "\n";
	cat.eat();
	cat.bark() //error
	cat.meow()

	return 0;
}

//Output: 
1 (true)
Animal is eating
The dog goes woof

1 (true)
Animal is eating
The cat goes meow
```

```c++

class Shape {
	public:
		double area;
		double volume;
};

class Cube : public Shape{
	public:
		double side;
	Cube(double side){
		this->side = side;
		this->area = side * side * 6;
		this->volume = side * side * side;
	}
}
class Sphere : public Shape {
	public: 
		double radius;
	Sphere(double radius) {
		this->radius = radius;
		this->area = 4 * 3.14159 * (radius * radius)
		this->volume = (4/3.0) * 3.14159 * (radius * 
											radius * radius);
		
	}
}

int main() {

	Cube cube(10);
	Sphere sphere(5);
	
	std::cout << "Area: " << cube.area << "cm^2\n";
	std::cout << "Volume: " << cube.Volume << "cm^3\n";
	
	std::cout << "Area: " << sphere.area << "cm^2\n";
	std::cout << "Volume: " << sphere.Volume << "cm^3\n";

	return 0;
}
//Output:
Area: 600cm^2
Volume: 1000cm^3

Area: 314.159cm^2
Volume: 523.598cm^3
```