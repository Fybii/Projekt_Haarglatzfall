## Assignment Operatoren
```js
x = 10;
y = 9;

x += y; // x = x + y 
x *= y; // x = x · y
x /= y; //x = x / y
x %= y; // x = x mod y = (10 / 9)
x **= y; // x = x^y = ...
```

## Inkrement und Dekrement 
```js
i = 1;

j = ++i; // j = 2
j = --i; // j = 1
```

## String-Operatoren
```js
str = ' James Bond ';
name = str.trim(); //'James Bond'
	   str.toLowerCase(); //'james bond'
	   str.toUpperCase(); //'JAMES BOND'

str = "Nagel, Schraube, 10"
list = str.split(",") // ["Nagel", "Schraube", "10"]
```

## Comparision Operatoren
```js
let x = 10, y = null;

if(x == "10") {...} //true
if(x === "10") {...} //false, different types
if(x !== "10") {...} //true
if(x != "10") {...} // false
if(x < "12") {...} //true
if(y === null) {...} //true
```

## Tenary Operator:
```js
variablenname = (condition) ? value1 /*if true*/ : value2; //else
voteable = (age < 18) ? "Ja" : "Nein";
```

## Logische Operatoren

- (**&&**) logisches und
```js
let x = 6, y = 3;
let check = (x < 10 && y > 1); //true
```

- (**||**) logisches oder
- (**!**) logisches not

```js
let x = 6, y = 3;
let check = !(x == 5 || y == 4); //true
```

## Automatische Typenorientierung
```js
let x = 5 + null; // x = 5
x = "5" + null; // x = "5null"
x = "5" + 2; // x = "52"
```

## Undefined, typeof
```js
let x;
let check1 = (x === undefined); // true
let check2 = (typeof x === 'undefined'); //true
```
