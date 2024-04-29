## DOM-Quoires
```js
//1. ID Selector:
const obj = document.getElementById("myID");
//-------------------------------------------------//
//2. Class Selector:
const elementHTMLCollection = document.getElementsByClassName("important");
for (let element of elementsHTMLCollection) {
	console.log(element.nodeName);
}
element0 = elementsHTMLCollection[0];
element0 = elementsHTMLCollection.item(0);
element = elementsHTMLCollection.namedItem("myID");
//---------------------------------------------------//
//3. CSS-Selector:
```
```html
<p class="c1">, <h1 class="c1">
```
```js
//gibt das erste Element im Dokument zurück
let elem = document.querySelector('p.c1');
```
```html
<p class="c1">, <h1 class="c1">
```
```js
let elements = document.querySelectorAll('c1');
elements.forEach(item => console.log(item));
//-------------------------------------------------//
//4. Tag-Selector
const attlist = document.getElementByTagName('article');
myArticle = attlist[0];
const firstSiblingArticle = myArticle.nextSibling;
if(firstSiblingArticle.nodeName === 'article') {
	firstSiblingArticle.className = "text--content";
	}
else {
	...
	}
```

## Inhalte und Attribue verändern
```js
element.innerText = "Ein neuer Text";
element.innerHTML = "Ein <strong>neuer</strong> Text.";

let lang = element.getAttribute('lang');
element.setAttribute('value', 'OK'); //button!
element.id;
element.className;

//Anfrage ob bestimmtes Attribute existiert
if(element.hasAttribute('style')) {
	element.removeAttribute('style')
}
```

## Design von DOM verändern
1. Über **className** $\rightarrow$ **Good Practice**
2. **Weniger gut** "inline-style setzen:
```js
element.setAttribute('style', 'fontsize: 20px');
```
3. **CSSOM-Tree** verändern
	- **style-Objekt : (`<link>`, `<style>`)**
```js
const styleSheet = document.styleSheets[0];
styleSheet.cssRules[0].style.backgroundcolor = "blue";
```

## Hinzufügen von HTML-Elementen per DOM
```js
//1.
const btn = document.createElement('button');
btn.innerHTML = "Click me";

//2. Target-Element (<form>)
objForm = document.getElementById('myForm');
objForm.appendChild(btn);
```
