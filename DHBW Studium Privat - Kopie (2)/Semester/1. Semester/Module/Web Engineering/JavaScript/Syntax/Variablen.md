- **Jede Anweisung** durch **Semikolon** ($;$) **abschließen

```js
let x = 10;
```
- **Ignoriert Leerzeichen** und **Zeilenumbrüche**
- **(`{...}`)-Code-Blöcke**

## Variablendeklaration
```js
let x; //undefined
let x = 10; //integer
let student = 'Alice'; //string
let quantity = 0.5; //numeric
let inStock = true; //boolean
let dataObject = null; //leere Variable

let price = 10.0, quantity = 5;
```

- **JS** verwendet die **Implizite Deklaration**
	- **Datentyp** wird bei **Wertzuweisung festgelegt.**

### Dynamische Typisierung
```js
let x = 10;
x = 'Alice';
```

## JavaScript-Bezeichner
- **case sensitive**

```js
let x;
let X;
```

- **Lower Camel Case-Syntax**
	- erster Buchstabe (**klein**)
	- **neues Wort** mit **Großbuchstaben beginnen

```js
let firstName;
let masterCard;
let userName;
```

## Konstanten in Javascript
```js
//Am Anfang eines Programmes mit Großbuchstaben
const PI = 3.1415; 

const parameter = 2 * PI;
```

- **const**: wird verwendet um **Arrays, Objekte** zu **definieren**.
- **Literale**: Darstellung von Werten
	- **String:** 'Das ist ...'
	- **Integer**: 10, 4711
	- **Nummeric**: 629, 3.14
	- **Exponent**: 5e2 ($5 · 10^2$), 3e-2($3·10^{-2}$)
	- **Hex**: 0x46 (70), ...
	- **Boolean**: true, false
	- **Null-Wert**: null

## Sichtbarkeit von Variablen
- **Variablen** die mit `let` oder `const` innerhalb eines **(`{...}`)-Code-Blocks** definiert werden, haben nur **lokale Gültigkeit** (**lokale Variablen**)
- 
```js
let z; // globale Variable

function multiply(x, y) {
//c ist nur innerhalb des Codeblocks gültig
	let c = x * y;
}
```

- Mittels `let` oder `const` **deklarierte Variablen** außerhalb eines **Code-Blocks** sind **außerhalb** und **innerhalb** des **Code-Blocks gültig** (**Globale Variable**)