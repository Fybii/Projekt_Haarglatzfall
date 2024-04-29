```js
const x [1,2,3];
let n = 3;

for (let i = 0, i < n, i++) {
	x[i] = x[i] * 4;
}
```

## Beispiel
```js
const person {
			 vName: "James",
			 nName: "Bond",
			 attr: "007",
			 }
let txt = "";

for(let i in person) {
	text += person[i] + '';
}
//text = "James Bond 007"
```

## for-of-Schleife
```js
const txtBausteine = ["1", "mal", "1", "=", "1"];
let message = "";
for (let x of txtBausteine) {
	message += x + ' ';
	console.log(x);
}
//message = "1 mal 1 = 1"
```

```js
const cars = ["Porsche", "Mercedes", "VW", "BMW"]; 
let i = 0; 
let text = ""; 
while (cars[i]) { 
	text += cars[i]; 
	console.log(cars[i]);
	 i++; 
	 }
```