## Arrays
- **Liste** an **Werten**, die einen **unterschiedlichen Typ** haben **können**.

```js
const array = [];
const array = ["Leiter", 45, "Personen"];

let str = array[0]; //str = "Leiter"
let i = array[1]; //i = 45

array[2] = "Bob";
```

## Arrays benutzen auch Methoden
```js
array.push(99); //["Leiter", 45, "Bob", 99]
let j = array.pop(); // 99 ["Leiter", 45, "Bob"]
console.log(array.length) // 3
```

```js
fruits = ["Ban", "Ora", "Apple", "Man"]
//lexikografische Sortierung (Unicode-Wert 1 vom ersten Buchstaben)
fruits.sort();
```

## Assoziative Arrays / Objekte
```js
const phoneBook = {};
const phoneBook = { "Alice": 2703,
					"Bob": 5412,
				    "Sally": 7711};
let phoneNumber = phoneBook = ["Alice"];
let phoneNumber = phoneBook.Alice;
phoneBook["Klaus"] = 7712;
delete phoneBook["Bob"];
```

```js
const objJohn = {
				firstName: "John",
				lastName: "Doe",
				id: 5566,
				fullName: function() {
							return this.firstname
							+ ""
							+ this.lastname;
							}
				}
let nameJohn = objJohn.fullName();
```